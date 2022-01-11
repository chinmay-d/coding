/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
// 176/176 cases passed (32 ms)
// Your runtime beats 86.22 % of cpp submissions
// Your memory usage beats 32.84 % of cpp submissions (56.8 MB)
class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string,int> m;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solveDuplicate(root);
        return res;
    }
    string solveDuplicate(TreeNode *node){
        if(node == NULL) return "";
        
        string left = solveDuplicate(node->left);                      // string to left
        string right = solveDuplicate(node->right);                    // string to right
        string s = "[" + left + to_string(node->val) + right + "]";    // string to current added a delimeter at start and end to differntiate between each element, helps in making the inorder substring unique

        if(m[s]!=-1) m[s]++;        // if key is present then increment the frequency
        if(m[s]>1) {                // if key is more than 1 that means the current node is the duplicate  
            res.push_back(node);    // then push the node in the node in the vector
            m[s]=-1;                // set the key again to its default value to avoid duplicate insertions in our 'res'
        }

        return s;
    }
};
// @lc code=end

