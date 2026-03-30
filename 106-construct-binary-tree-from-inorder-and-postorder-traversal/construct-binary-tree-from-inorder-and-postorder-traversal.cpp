class Solution {
public:
 unordered_map<int, int> mp;
    TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd){
            if (postStart > postEnd || inStart > inEnd)
            return NULL;
            int rootval = postorder[postEnd];
            TreeNode* root = new TreeNode(rootval);
            int inroot = mp[rootval];
            int leftsize = mp[rootval] - inStart;
            root->left = helper(postorder,postStart,
                            postStart + leftsize - 1,inorder,inStart,inroot-1);
            root->right = helper(postorder,postStart + leftsize,postEnd-1,inorder,inroot+1,inEnd);
            return root;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return helper(postorder, 0, postorder.size()-1, inorder , 0 , inorder.size()-1);
    }
};