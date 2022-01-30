/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode* dummy = head;
    
        while(dummy){
            counter++;
            dummy=dummy->next;
        }
    
        if(counter==n){
            return head->next;
        }
    
        ListNode* res = head;
    
        ListNode* link = new ListNode(0);
        link->next=head;

        while(head){

            if(counter==n){
                head = link;
                head->next = head->next->next;
                break;
            }

            head = head->next;
            link = link->next;
            counter--;
        }
	    return res;
    }
};
// @lc code=end

