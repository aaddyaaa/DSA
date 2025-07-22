/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: root is null or value is found
        if (root == nullptr || root->val == val)
            return root;

        // If value is smaller, search left subtree
        if (val < root->val)
            return searchBST(root->left, val);

        // If value is greater, search right subtree
        return searchBST(root->right, val);
    }
};
