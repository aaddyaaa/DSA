class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* prev = NULL;
            for(int i = 0;i<n; i++){
                Node* node = q.front();
                q.pop();
                if (prev != NULL) {
                    prev->next = node;
                }
                prev = node;
                if(node->left!= NULL) q.push(node->left);
                if(node->right!= NULL) q.push(node->right);
                
            }
            
        }
        return root;
    }
};