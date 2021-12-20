/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
// ""123456789"\n"987654321""
// ""498828660196"\n"840477629533""
class Solution {
public:
    string multiply(string n, string m) 
    {
        if(m == "0"||n == "0") return ("0");                          //If any string is equal to 0, then the product is 0,therefore return 0
            
        if(n.size() > m.size()) swap(m,n);
        int x = m.size(),y = n.size(),carry = 0,i,j;                  //x is the length of longer string and y is length of smaller string
        string answer(x+y,'0');                                       //Auxiliary String containing (x+y) 0s, answer can't exceed (x+y) in length
        for(i = y-1;i >= 0;i--,carry = 0)                             //Multiply by each digit of the larger string m with (i)th digit of n from the end
        {
            for(j = x-1;j >= 0;j--)                                   //(j)th digit of m is to be multiplied with (i)th digit of n
            {
                int t = (m[j] - '0') * (n[i] - '0')  + (answer[i + j + 1] - '0') + carry;  //t stores product of digits + value already at (i+j+1)th position in the string + carry
                carry = t/10;                                         //Carry = entire sum divided by 10;
                answer[i + j + 1] = char(t%10 + '0');                 //(i+j+1)th position = sum modulus 10,i.e remainder
            }
            //If carry is greater than 0, then we will store carry in the immidiate preceding place in the  answer  string
            answer[i + j + 1] =  char(carry + '0');
        }
        //Its mentioned before that length of answer string can either be equal to (x+y) or (x+y-1), nothing else, unless one of them is 0

        if(answer[0] == '0')  return (answer.substr(1));
        return answer;
    }

};
// @lc code=end

