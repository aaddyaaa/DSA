class Solution {
public:
int helper(TreeNode* node,  int curr){
    if (node == NULL) return 0;
    curr = curr*10 + node->val;
    if(node->left == NULL && node->right == NULL) return curr;
    return (helper(node->left , curr)+helper(node->right , curr));
}
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};