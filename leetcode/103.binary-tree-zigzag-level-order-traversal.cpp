/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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


// 33/33 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.42 % of cpp submissions (12.2 MB)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        bool ltr = true;
        
        stack<TreeNode*> ms, cs;
        vector<int> temp;
        ms.push(root);

        while(!ms.empty()){
            TreeNode *node = ms.top();
            ms.pop();
            
            if(node){
                // Add to temp
                temp.push_back(node->val);
        
                // Left to right
                if(ltr){
                    if(node->left) cs.push(node->left);
                    if(node->right) cs.push(node->right);
                }
                // Right to left
                else{
                    if(node->right) cs.push(node->right);
                    if(node->left) cs.push(node->left);
                }

            }
            // if main stack is empty
            if(ms.empty()){
                ltr = !ltr;           // reverse the flag
                res.push_back(temp);  // append temp to the result
                temp.clear();         // clear temp
                swap(ms,cs);          // swap cs with ms
            }
        }
        return res;
    }
};
// @lc code=end

