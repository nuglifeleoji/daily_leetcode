class Solution {
    public:
        int countNodes(TreeNode* root) {
            if(root==nullptr) return 0;
            int lh=height(root->left);
            int rh=height(root->right);
            if(lh==rh){
                return (1<<lh)+countNodes(root->right);
            }
            else{
                return (1<<rh)+countNodes(root->left);
            }
        }
        int height(TreeNode* root){
            int height=0;
            while(root!=nullptr){
                height++;
                root=root->left;
            }
            return height;
        }
    };