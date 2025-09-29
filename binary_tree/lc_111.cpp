class Solution {
    public:
        int minx=INT_MAX;
        int minDepth(TreeNode* root) {
            if(!root){
                return 0;
            }
            dfs(root,0);
            return minx;
        }
        void dfs(TreeNode* root, int height){
            height+=1;
            if(root->left==nullptr && root->right==nullptr){
                minx=min(minx, height);
            }
            if(root->left){
                dfs(root->left, height);
            }
            if(root->right){
                dfs(root->right, height);
            }
        }
    };