/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length()-1;
        int n2=num2.length()-1;
        string ans;
        if(n1>n2)
            ans=num1;
        else
            ans=num2;
        int n=ans.length()-1;
        int sum=0;
        while(n1>=0 || n2>=0){
            if(n1>=0){
                sum+=num1[n1]-'0'; //subtracting '0' from the string converts the digit to an int                
                n1--;
            }
            if(n2>=0)
            {
                sum+=num2[n2]-'0';
                n2--;
            }
            ans[n]=sum%10+'0';
            sum=sum/10;
            n--;
        }
        if(sum){
            ans.insert(ans.begin(),'0'+sum); // adding '0' in front converts the digit from int to string
        }
        return ans;
    }
};
// @lc code=end

