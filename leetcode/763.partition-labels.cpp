/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
//""caedbdedda""
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        
        vector<int> last_pos(128,0); // in total 128 possible char/ascii
        for (int i = 0; i < s.size(); i++) {
            last_pos[s[i]] = i; // s[i]'s last position is i
        }
        
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_pos[s[i]]);// end pos of ith char
            if (end == i) { // currently i is end, then cut it here
                ans.push_back(end - start + 1);
                // update start to end+1th position
                start = end+1;
            }
        }
        return ans;
    }
};
// @lc code=end

