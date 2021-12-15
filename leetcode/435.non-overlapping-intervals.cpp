/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // if(intervals.size()<2) return 0;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1];
        for(size_t i=0; i<intervals.size(); i++){
            // if no overlapping
            if(intervals[i][0]>=end){
                res.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            // overlapping
            else end = min(intervals[i][1],end);
        }
        res.push_back({start,end});

        // for(int i=0;i<res.size();i++){
        //     for(int j=0;j<res[0].size();j++){
        //         cout<<res[i][j] << " ";
        //     }
        //     cout <<endl;
        // }
        return intervals.size()-res.size();
    }
};
// @lc code=end

