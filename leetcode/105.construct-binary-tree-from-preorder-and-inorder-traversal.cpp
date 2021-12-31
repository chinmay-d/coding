/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
// "[1,2,3]\n[3,2,1]"
class Solution {
public:
    unordered_map<int,int>m; // unordered_map is used to make the code faster (searching in inorder)
    int i=0;
    TreeNode *treeHelper(vector<int> &pre, vector<int>&in, int s, int e){
        // boundary conditions
        if(s>e) return NULL;

        // the first element of preorder is the root always
        TreeNode *node = new TreeNode(pre[i++]);

        // find the index of the root in the unordered_map m
        int mid = m[node->val];
        
        // recursively add subtrees
        node->left = treeHelper(pre,in,s,mid-1);
        node->right = treeHelper(pre,in,mid+1,e);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        for(int i=0;i<size;i++)
            m[inorder[i]]=i;
        return treeHelper(preorder,inorder,0,size-1);
    }
};
// @lc code=end

