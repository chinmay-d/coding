/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
//[1,1,1,2,3]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> hmap;
        ListNode *temp = head;
        // map the frequencies of the sorted nos
        while(temp){
            if(!hmap[temp->val]) hmap[temp->val] = 1;
            else hmap[temp->val]++;
            temp = temp->next;
        }

        // make a new Listnode and make a new linkedlist
        // with only the non-repeating elements
        ListNode *res = new ListNode(-1);
        temp = res;
        for(auto [key,val]:hmap){
            if(val == 1){
                ListNode *t = new ListNode(key);
                temp->next = t;
                temp = temp->next;
            }
        }
        return res->next;
    }
};
// @lc code=end

