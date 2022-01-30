/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while(curr){
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
        }

        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head->next) return head;
        
        if(!head->next->next){
            if(head->val != head->next->val) return false;
            else return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* ll = reverseList(slow->next);
        
        fast = head;
        while(ll){
            if(fast->val != ll->val) return false;
            fast = fast->next;
            ll = ll->next;
        }
        return true;
    }
};
// @lc code=end

