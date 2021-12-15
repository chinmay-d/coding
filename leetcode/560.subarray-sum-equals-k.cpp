/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
//[1,2,3]\n3
//[1]\n1
//[2,2,6]\n0
//[1,-1,0]\n0
//[0,0,0]\n0
//[1,2,1,2,1]\n3
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c=0, sum=0;
        std::map<int,int> hmap;
        // 
        for(int i=0;i<nums.size();i++) { 
            sum += nums[i];
            if(sum==k) c++;
            if(hmap.find(sum-k)!=hmap.end()) {c+=hmap[sum-k];}
            hmap[sum]++;
        }
        return c;
    }
};
// @lc code=end

