/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class unionFind{    
public:
    vector<int> root;
    vector<int> rank;
    int count;
    
    unionFind(int size):root(size),rank(size),count(size){
        for(auto i=0;i<size;i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void unionset(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]) root[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) root[rootX] = rootY;
            else{
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count --;
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, string> m;
        
        // return the string if there are no edges
        if(pairs.size()==0) return s;
    
        int n = s.length();
        
        unionFind uf(n);
        
        // connect the graph
        for(auto pair: pairs)
            uf.unionset(pair[0], pair[1]);
       
        // return the sorted string if all the nodes of the graph are connected
        if(uf.count==1){
            sort(s.begin(), s.end());
            return s;
        }
        
        // map root to the string chars
        for(int i=0; i<n; i++){
            int root = uf.find(i);
            uf.root[i] = root;
            m[root] += s[i];
        }
        
        // sort the string value in the map in descending order 
        for(auto pairs:m){           
            int i=pairs.first;
            string s=pairs.second;
            sort(s.begin(), s.end(), greater<char>());
            m[i]=s;
        }
        
        // store the resultant answer in the original string and return it
        for(int i=0; i<n; i++){
            int root=uf.find(i);
            s[i]=m[root].back();
            m[root].pop_back();
        }
        return s;
    }
};
// @lc code=end

