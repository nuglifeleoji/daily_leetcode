class Solution {
    public:
        struct ReturnType{
            int min, max, size;
            bool isBST;
            ReturnType(int mn, int mx, int sz, bool bst){
                min=mn;
                max=mx;
                size=sz;
                isBST=bst;
            }
        };
        int maxSize=0;
        int largestBSTSubtree(TreeNode* root) {
            maxBST(root);
            return maxSize;
        }
        ReturnType maxBST(TreeNode* root){
            if(root==nullptr){
                return ReturnType(INT_MAX, INT_MIN, 0, true);
            }
            ReturnType l1=maxBST(root->left);
            ReturnType l2=maxBST(root->right);
            if(root->val>l1.max && root->val<l2.min && l1.isBST && l2.isBST){
                maxSize=max(maxSize, l1.size+l2.size+1);
                return ReturnType(min(l1.min, root->val), max(l2.max, root->val), l1.size+l2.size+1, true);
            }2
            else{
                return ReturnType(l1.min, l2.max, l1.size+l2.size+1, false);
            }
        }
    };