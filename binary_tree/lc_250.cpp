class Solution {
    public:
        int count=0;
        int countUnivalSubtrees(TreeNode* root) {
            if(!root){
                return 0;
            }
            else{
                countUnivalSubtrees(root->left);
                countUnivalSubtrees(root->right);
                if(isUni(root, root->val)){
                    count++;
                }
                return count;
            }
        }
        bool isUni(TreeNode* root, int k){
            if(root==nullptr){
                return true;
            }
            if(root->val !=k){
                return false;
            }
            if(isUni(root->left, k) && isUni(root->right, k)){
                return true;
            }
            return false;
        }
    };