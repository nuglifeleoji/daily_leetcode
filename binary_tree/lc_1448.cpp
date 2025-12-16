class Solution {
    public:
        int count=0;
        int goodNodes(TreeNode* root) {
            dfs(root, INT_MIN);
            return count;
        }
        void dfs(TreeNode* root, int prev){
            if(root==nullptr){
                return;
            }
            if(root->val>=prev){
                count++;
            }
            prev=max(prev,root->val);
            dfs(root->left, prev);
            dfs(root->right, prev);
        }
    };