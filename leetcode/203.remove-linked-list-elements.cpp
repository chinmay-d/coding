/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = new ListNode(-1);
        ListNode* res = node;
        while(head){
            // cout<< head->val << endl;
            if(head->val != val){
                ListNode* t = new ListNode(head->val);
                node->next = t;
                node = node->next;
            }
            head = head->next;
        }
        if(res->next == NULL) return NULL;
        return res->next;
    }
};
// @lc code=end

