/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
//""ccc""
//""bananas""
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.length()==1) return 1;
        int c=0;
        map<char,int> hmap;
        for(auto i:s){
            if(!hmap[i]) hmap[i]=1;
            else hmap[i]++;
        }
        if(hmap.size()==1) return s.length();
        for(auto [key,value]:hmap){
            if(value%2==1) c++;
        }
        cout<<c;
        if(c==0) return s.length();
        return s.length()-(c-1);
    }
};
// @lc code=end

