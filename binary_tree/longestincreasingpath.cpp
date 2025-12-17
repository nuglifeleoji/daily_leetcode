class Solution{
    public:
        int global=1;
        int longestIncreasingPath(TreeNode* root) {
            if(root==nullptr){
                return 0;
            }
            if(root->left==nullptr && root->right==nullptr){
                return 1;
            }
            int cur=1;
            if(root->left!=nullptr){
                if(root->left->val>root->val){
                    int left=longestIncreasingPath(root->left);
                    global=max(global, left+1);
                    cur=max(cur, left+1);
                }
            }
            if(root->right!=nullptr){
                if(root->right->val>root->val){
                    int right=longestIncreasingPath(root->right);
                    global=max(global, right+1);
                    cur=max(cur, right+1);
                }
            }
            return cur;
        }
}