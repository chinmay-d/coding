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
// 55/55 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 53.8 % of cpp submissions (7.5 MB)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *odd = head;                       // set odd to head
        ListNode *even = head->next;                // set even to head->next
        while(even && odd){           
            swap(odd->val,even->val);               // swap odd and even if they both exist
            if(even->next && even->next->next){     // check if next odd and even exist   
                odd = even->next;                   // if they exist,
                even = odd->next;                   // then set odd and even
            }
            else break;
        }
        return head;
    }
};
// @lc code=end

