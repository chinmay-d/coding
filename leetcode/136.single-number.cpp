/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=NULL;
        for(int i=0;i<nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end

