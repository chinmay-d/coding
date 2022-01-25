/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slw = head;
        ListNode* fst = head;
        if(!slw->next || !fst->next || !fst->next->next) return false;
        while(slw->next != NULL || fst->next->next != NULL){
            if(!slw->next || !fst->next || !fst->next->next) return false;
            slw = slw->next;
            fst = fst->next->next;
            if(slw == fst){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

