/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    int pascal(int row, int col){
        if(col == 0 || col == row){
            return 1;
        }
        else{
            return pascal(row-1, col-1) + pascal(row-1,col);
        }
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j <= i; j++){
                int v = pascal(i,j);
                triangle[i].push_back(v);
            }
        }
        return triangle;
    }
};
// @lc code=end

