/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode(-1);
        vector<int> vec;
        
        while(list1){
            vec.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2){
            vec.push_back(list2->val);
            list2 = list2->next;
        }
        sort(vec.begin(),vec.end());
        
        ListNode* temp = res;
        for(auto val:vec){
            ListNode* t = new ListNode(val);
            temp->next = t;
            temp = temp->next;
        }
        return res->next;
    }
    
};
// @lc code=end

