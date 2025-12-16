class Solution {
    public:
        int sum=0;
        int sumRootToLeaf(TreeNode* root) {
            dfs(root, 0);
            return sum;
        }
        void dfs(TreeNode* root, int prev){
            prev=prev*2+root->val;
            if(root->left ==nullptr && root->right==nullptr){
                sum+=prev;
                return;
            }
            if(root->right){
                dfs(root->right, prev);
            }
            if(root->left){
                dfs(root->left, prev);
            }
        }
    };