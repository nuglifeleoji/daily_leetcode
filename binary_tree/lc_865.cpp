class Solution {
    public:
         TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            unordered_set<TreeNode*> deepest = getDeepest(root);
            return LCA(root, deepest);
        }
        
        TreeNode* LCA(TreeNode* root, unordered_set<TreeNode*>& deepest) {
            if (root == nullptr || deepest.count(root)) {
                return root;
            }
            
            TreeNode* left = LCA(root->left, deepest);
            TreeNode* right = LCA(root->right, deepest);
            
            if (left && right) {
                return root;
            }
            return left ? left : right;
        }
        
        unordered_set<TreeNode*> getDeepest(TreeNode* root) {
            unordered_set<TreeNode*> deepest;
            if (!root) return deepest;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int levelSize = q.size();
                deepest.clear();  
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    deepest.insert(node);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                if (q.empty()) {
                    return deepest;
                }
            }
            return deepest;
        }
    };