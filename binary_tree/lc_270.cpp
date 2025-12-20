class Solution {
    public:
        int closestValue(TreeNode* root, double target) {
            if(root->val==target){
                return root->val;
            }
            else if(root->val>target){
                if(root->left==nullptr){
                    return root->val;
                }
                else{
                    int g=closestValue(root->left, target);
                    return abs(g-target)<=abs(root->val-target)? g: root->val;
                }
            }
            else{
                if(root->right==nullptr){
                    return root->val;
                }
                else{
                    int g=closestValue(root->right, target);
                    return abs(root->val-target)<=abs(g-target)? root->val: g;
                }
            }
        }
    };