/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int minind;
        double numerator;
        nums2.insert(nums2.end(),nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int size = nums2.size();
        if (size % 2 == 0){
            minind = (size/2)-1;
            numerator = nums2[minind]+nums2[++minind];
            return numerator/2.0;
        }
        else{
            minind = (size/2);
            return nums2[minind];
        }
    }
};
// @lc code=end

