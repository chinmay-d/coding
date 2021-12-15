/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cur = 1;
        vector solve(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++){
            solve[i] *= cur;
            cur *= nums[i];
        }
        cur = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            solve[i] *= cur;
            cur *= nums[i];
        }
        return solve;
    }
};
// @lc code=end

