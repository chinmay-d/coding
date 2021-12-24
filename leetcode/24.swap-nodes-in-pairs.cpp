/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *odd = head;
        ListNode *even = head->next;
        int temp;
        while(even && odd){
            swap(odd->val,even->val);
            if(even->next && even->next->next){
                odd = even->next;
                even = odd->next;
            }
            else break;
        }
        return head;
    }
};
// @lc code=end

