/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hmap;
        string temp;
        for(auto str:strs){
            temp = str;
            sort(str.begin(),str.end());
            hmap[str].push_back(temp);
        }

        vector<vector<string>> res;
        for(auto [key,val]:hmap) res.push_back(val);
        return res;
    }
};
// @lc code=end

