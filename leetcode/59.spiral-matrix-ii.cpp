/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int no = 1;
        // Defining the boundaries of the matrix.
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        
        // Defining the direction in which the array is to be traversed.
        int dir = 1;
        
        while (top <= bottom && left <= right) {

            if (dir == 1) {    // moving left->right
                for (int i = left; i <= right; ++i) {
                    matrix[top][i] = no;
                    no++;
                }
                // Since we have traversed the whole first
                // row, move down to the next row.
                ++top;
                dir = 2;
            } 
            else if (dir == 2) {     // moving top->bottom
                for (int i = top; i <= bottom; ++i) {
                    matrix[i][right] = no;
                    no++;
                }
                // Since we have traversed the whole last
                // column, move left to the previous column.
                --right;
                dir = 3;
            } 
            else if (dir == 3) {     // moving right->left
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = no;
                    no++;
                }
                // Since we have traversed the whole last
                // row, move up to the previous row.
                --bottom;
                dir = 4;
            } 
            else if (dir == 4) {     // moving bottom->up
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = no;
                    no++;
                }
                // Since we have traversed the whole first
                // col, move right to the next column.
                ++left;
                dir = 1;
            }
        }
        return matrix;
    }
};
// @lc code=end

