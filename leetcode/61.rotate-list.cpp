/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(k == 0 or(head and !head->next)) return head;
        int c = 0;
        ListNode* h = head;
        while(h){
            c++;
            h = h->next;
        }
        
        if(k==c) return head;
        else if(k>c) k = k % c;
        
        if(k==0) return head;
        
        h = head;
        int pos = c-k;
        while(pos-1!=0){
            h = h->next;
            pos--;
        }
        
        ListNode* ll = h->next;
        h->next = NULL;
        
        h = ll;
        while(h->next != NULL){
            h = h->next;
        }
        h->next = head;
        return ll;
    }
};
// @lc code=end

