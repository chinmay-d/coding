/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *t = head;
        vector<int> vec;

        // insert all the LL values in a vector
        while(t){
            vec.push_back(t->val);
            t = t->next;
        }

        // reverse the vector in k groups
        if(k>vec.size()) return head;
        else if(k==vec.size()){
            reverse(vec.begin(),vec.end());
        }
        else{
            int s = vec.size();
            int start = 0, end = k;
            while(k<=s){
                reverse(vec.begin()+start,vec.begin()+end);
                start += k;
                end += k;
                s -= k;
            }
        }

        // make a LL with the vals of the vector
        ListNode *res = new ListNode();
        t = res;
        for(auto val:vec){
            ListNode *temp = new ListNode(val);  
            t->next = temp;
            t = t->next;            
        }
        return res->next;
    }
};
// @lc code=end

