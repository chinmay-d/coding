/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1=headA,*ptr2=headB; //take two pointers
        if(headA==NULL or headB==NULL) return NULL; //check base case
        
        while(ptr1!=ptr2){
            ptr1= ptr1==NULL?headA:ptr1->next; //assign to head of other LL if it become null
            ptr2= ptr2==NULL?headB:ptr2->next; //same as above
        }
        return ptr1; //when both pointers matches then return
    }
};
// @lc code=end

