class BSTIterator {
private:
    stack<TreeNode*> st;

    // Push all left children of node to stack
    void pushLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root); // initialize with leftmost path
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();
        if (node->right) {
            pushLeft(node->right); // explore right subtree
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
