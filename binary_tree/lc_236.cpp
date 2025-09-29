class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return LCA(root, p, q);
        }
        TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
            if(root==nullptr){
                return root;
            }
            if(root==p || root==q){
                return root;
            }
            TreeNode* t1=LCA(root->left, p,q);
            TreeNode* t2=LCA(root->right, p,q);
            if(t1 && t2){
                return root;
            }
            if(!t1){
                return t2;
            }
            else{
                return t1;
            }
            
        }
    };