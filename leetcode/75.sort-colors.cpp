/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> newvec;
        int no1 = 0, no0 = 0, no2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) no0 += 1;
            else if(nums[i] == 1) no1 += 1;
            else no2 += 1;
        }
        while(no0 !=0){
            newvec.push_back(0);
            no0-=1;
        }
        while(no1 !=0){
            newvec.push_back(1);
            no1-=1;
        }
        while(no2 !=0){
            newvec.push_back(2);
            no2-=1;
        }
        nums = newvec;
    }
};
// @lc code=end

