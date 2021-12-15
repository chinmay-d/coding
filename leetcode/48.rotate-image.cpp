/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(size_t i=0; i<matrix.size()/2; i++){
            matrix[i].swap(matrix[matrix.size()-i-1]);
        }

        for(size_t i=0; i<matrix.size(); i++){
            for(size_t j=0; j<i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
// @lc code=end

