/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *node = head;
        bool c = 0;
        int sum;
        while(l1 || l2 || c){
            sum=0;
            if(l1 && l2){
                sum = l1->val + l2->val + c;
                l1 = l1-> next;
                l2 = l2->next;
            }
            else if (l1){
                sum = l1->val + c;
                l1 = l1->next;
            }
            else if (l2){
                sum = l2->val + c;
                l2 = l2->next;
            }
            else if(c){
                sum = c;
            }
            
            if(sum>9){sum-=10;c=1;}
            else c=0;

            ListNode *temp = new ListNode(sum);
            node->next = temp;
            node = temp;
        }
        return(head->next);

    }
};
// @lc code=end

