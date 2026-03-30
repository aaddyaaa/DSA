class Solution {
public:
    unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd){
            if (preStart > preEnd || inStart > inEnd)
            return NULL;
            int rootval = preorder[preStart];
            TreeNode* root = new TreeNode(rootval);
            int inroot = mp[rootval];
            int leftsize = mp[rootval] - inStart;
            root->left = helper(preorder,preStart+1,preStart+leftsize,inorder,inStart,inroot-1);
            root->right = helper(preorder,preStart+leftsize+1,preEnd,inorder,inroot+1,inEnd);
            return root;
                    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return helper(preorder, 0 , preorder.size()-1, inorder , 0 , inorder.size()-1);
    }
};