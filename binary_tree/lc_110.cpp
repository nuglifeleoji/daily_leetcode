class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if(root==nullptr) return true;
            int h1=height(root->left);
            int h2=height(root->right);
            return abs(h1-h2)<=1 && isBalanced(root->left) && isBalanced(root->right);
        }
        int height(TreeNode* root){
            if(root==nullptr) return 0;
            return max(height(root->left), height(root->right))+1;
        }
    };