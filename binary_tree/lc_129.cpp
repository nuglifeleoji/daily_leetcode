class Solution {
    public:
        int sum=0;
        int sumNumbers(TreeNode* root) {
            dfs(root, 0);
            return sum;
        }
        void dfs(TreeNode* root, int prev){
            prev=prev*10+root->val;
            if(root->left==nullptr && root->right==nullptr){
                sum+=prev;
                return;
            }
            else{
                if(root->left){
                    dfs(root->left, prev);
                }
                if(root->right){
                    dfs(root->right, prev);
                }
            }
        }
    };