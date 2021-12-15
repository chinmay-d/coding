/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        int first_min=INT_MAX, second_min=INT_MAX;
        for(int i: nums){
            if(i<=first_min){
                first_min=i;
            }
            else if(i<=second_min){
                second_min=i;
            }
            else return true;
        }
        return false;
    }
};
// @lc code=end

