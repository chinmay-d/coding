/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        return (1 + soln(n,k));
    }

    int soln(int n, int k){
        if(n==1) return 0;
        int x = soln(n-1, k);
        int y = (x+k) % n;
        return y;
    }
};
// @lc code=end

