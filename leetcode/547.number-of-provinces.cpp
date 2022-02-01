/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class unionFind{
private:
    vector<int> root;
    vector<int> rank;
    int count;

public:
    unionFind(int size):root(size), rank(size), count(size){
        for (int i=0; i<size; i++){
            root[i] = i;                 // set connection of a node to itself
            rank[i] = 1;                 // initially set rank or each node as 1
        }
    }

    int find(int x){
        if(x == root[x]) return x;      // return the root x
        return root[x] = find(root[x]); // set every below node to its root, done for optimization
    }

    void Union(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx != rooty){
            if(rank[rootx] > rank[rooty]) root[rooty] = rootx;        // attach smaller graph to
            else if(rank[rootx] < rank[rooty]) root[rootx] = rooty;   // the bigger graph
            else{
                root[rootx] = rooty;      // if the rank of both graphs is same then set root of y as the root
                rank[rooty]++;            // and increment the rank of the root of the overall graph

            }
            count --;                     // reduce the count if rootx != rooty
        }
    }

    int getCount(){
       return count;                      // return the reduced count
    } 
    
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 0) return 0;
        
        int n = isConnected.size();
        
        unionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) uf.Union(i,j);          // if there is a conection in the given matrix then make it using the Union function
            }
        }
        
        return uf.getCount();
        
    }
};


// @lc code=end

