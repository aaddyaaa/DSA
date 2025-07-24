class Solution {
public:
    int index = 0;

    TreeNode* buildBST(vector<int>& preorder, int lower, int upper) {
        if (index >= preorder.size()) return nullptr;

        int val = preorder[index];
        if (val < lower || val > upper) return nullptr;

        index++;
        TreeNode* root = new TreeNode(val);
        root->left = buildBST(preorder, lower, val - 1);
        root->right = buildBST(preorder, val + 1, upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MIN, INT_MAX);
    }
};
