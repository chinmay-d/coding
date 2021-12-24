/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode *reverseLL(ListNode *head){
        ListNode *node = NULL;
        while(head){
            ListNode *prev = new ListNode(head->val);
            prev->next = node;
            node = prev;
            head = head->next;
        }
        return node;
    }
    void reorderList(ListNode* head) {
        ListNode *l1 = head;
        int s = 0;
        while(l1){
            s++;
            l1 = l1->next;
        }      

        l1 = head;
        int c = 1;
        while(c!=ceil(s/2.0)){
            l1 = l1->next;
            c++;
        }

        ListNode *newll = l1->next;
        l1->next = NULL;

        ListNode *revll = reverseLL(newll);  // reverse the list
        ListNode *l2 = revll;

        l1 = head;
        while(l1 && l2){
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;

            if(l1_next == NULL) break;

            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
};
// @lc code=end

