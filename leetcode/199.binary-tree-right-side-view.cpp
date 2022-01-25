/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;   // return empty vector if root is NULL
        
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int n = q.size();                           // n is the number of nodes present in the current level of the tree
            for(int i=0;i<n;i++){             
                TreeNode* curr = q.front();             // push topmost node in curr
                q.pop();                                // pop that node from the queue

                if(i == n-1){                           // if i is at (n-1)th position then push the value in the res 
                    res.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);      // if left exists then push it inside the queue
                if(curr->right) q.push(curr->right);    // if right exists then push it inside the queue
            }
        }
        
        return res;    
    }
};
// @lc code=end

