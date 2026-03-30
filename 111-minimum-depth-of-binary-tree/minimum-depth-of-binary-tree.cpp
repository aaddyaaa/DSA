class Solution {
public:
int helper(TreeNode* root){
    if (root == NULL) return 0;
    int lh = helper(root->left);
    int rh = helper(root->right);
    if (root->left == NULL) return 1 + rh;
    if (root->right == NULL) return 1 + lh;

    return (1+min(lh,rh));
}
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};