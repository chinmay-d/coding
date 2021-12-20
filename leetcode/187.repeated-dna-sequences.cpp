/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
//""AAAAAAAAAAA""
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() < 10) return res;
        unordered_map<string,int> hmap;
        int i=0;
        while(i<=s.length()-10){
            if(!hmap[(s.substr(i,10))]) hmap[(s.substr(i,10))] = 1;
            else hmap[(s.substr(i,10))]+=1;
            i++;
        }

        for(auto [key,val]:hmap){
            if(val>1) res.push_back(key);
        }
        return res;
    }
};
// @lc code=end

