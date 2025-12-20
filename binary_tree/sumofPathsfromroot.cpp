class Solution{
    public:
        int global=0;
        int total(TreeNode* root){
            if(root==nullptr){
                return 0;
            }
            dfs(root, 0, 0);
            return global;
        }
        void dfs(TreeNode* root, int prev, int depth){
            if(root==nullptr){
                return;
            }
            if(root->left==nullptr && root->right==nullptr){
                global+=prev+pow(10, depth)*root->val;
            }
            dfs(root->left, prev+pow(10, depth)*root->val, depth+1);
            dfs(root->right, prev+pow(10, depth)*root->val, depth+1);
            return;
        }
};
