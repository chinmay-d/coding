/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
// ""())()(((""
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        for(auto i=0;i<s.length();i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]==')'){
                if(st.empty()){
                    // erase the char ')'
                    s.erase(i, 1);
                    i --;
                }
                else st.pop();
            }
        }

        // check remaining '(' in the stack
        if(!st.empty()){
            for(auto i=s.length();i>=0;i--){
                if(st.empty()) break;
                if(s[i]=='('){
                    s.erase(i, 1);
                    i++;
                    st.pop();
                }
            }
        }
        return s;
    }
};
// @lc code=end

