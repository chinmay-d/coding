/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=0,res;
        map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        for(auto [key,value]:freq){
            if(value>n) {n = value; res = key;}
        }
        return res;
    }
};
// @lc code=end

