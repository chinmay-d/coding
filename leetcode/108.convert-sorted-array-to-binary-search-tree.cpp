/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        TreeNode *node = new TreeNode();
        node = createTreeFromSortedArr(nums,0,nums.size()-1);
        return node;
    }
    TreeNode *createTreeFromSortedArr(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int midpoint = left + (right-left)/2;
        TreeNode *node = new TreeNode(nums[midpoint]);
        node->left = createTreeFromSortedArr(nums,left,midpoint-1);
        node->right = createTreeFromSortedArr(nums,midpoint+1,right);
        
        return node;
    }
};
// @lc code=end

