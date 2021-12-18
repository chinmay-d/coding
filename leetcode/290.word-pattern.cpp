/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
//""abba"\n"dog cat cat fish""
//""e"\n"eukera""
//""deadbeef"\n"d e a d b e e f""
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size()-1!=(count(s.begin(), s.end(), ' ')))
            return false;

        unordered_map<char,string> m;
        unordered_map<string,char> n;
        stringstream str(s); 
        string word;
        for(auto i:pattern){
            str >> word;
            if((m[i] == "" && n[word] == 0)){
                m[i] = word;
                n[word] = i;
            }
            else if(m[i]!=word)
                return false;
        }
        return true;
    }
};
// @lc code=end

