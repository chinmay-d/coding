/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
// ""cbbd""
// ""bb""
// ""ccd""
// ""aacabdkacaa""
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1) return s;
        std::string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            std::pair<int, int> one = helper(s, i, i); // expand from center for odd length palindrome
            std::pair<int, int> two = helper(s, i, i+1); // expand from center for even length palindrome
            
			// choose the longer of the palindromes to use
            std::pair<int, int> temp;
            if (one.second - one.first > two.second - two.first)
                temp = one;
            else
                temp = two;
            
            int l = temp.first;
            int r = temp.second;
            int len = r - l + 1;
            
            if (len > ans.size())
                ans = s.substr(l, len);
        }
        return ans;
    }
    
    std::pair<int, int> helper(const string& s, int l, int r)
    {
        int last_l = 0;
        int last_r = 0;
        while (l >= 0 && r < s.size())
        {
            if (s[l] != s[r])
                break;
            
            last_l = l;
            last_r = r;
            
            l--;
            r++;
        }
        return std::make_pair(last_l, last_r);
    }

};
// @lc code=end

