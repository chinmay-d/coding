/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1];
        for(size_t i=0; i<intervals.size(); i++){
            // if no overlapping
            if(intervals[i][0]>end){
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // overlapping
            else end = max(intervals[i][1],end);
        }
        res.push_back({start,end});
        return res;
    }
};
// @lc code=end

