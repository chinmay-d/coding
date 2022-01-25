/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
// [1,2,3,4,5,6,7,8]
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        if(head && head->next && head->next->next){
            ListNode* temp = head;
            ListNode* t = head;

            while(t->next != NULL){
                t = t->next;
            }

            ListNode* end = t;
            while(temp != end){
                ListNode* mv = temp->next;
                if(mv == end) {
                    temp->next = mv->next;
                    t->next = mv;
                    mv->next = NULL;
                    break;
                }
                temp->next = mv->next;
                mv->next = NULL;
                t->next = mv;
                t =  t->next;
                temp = temp->next;
            }
        }
        return head;
    }
};
// @lc code=end

