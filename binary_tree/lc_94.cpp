class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            TreeNode* pre=nullptr;
            TreeNode* cur=root;
            stack<TreeNode*> stack;
            while(stack.size()!=0 || cur!=nullptr){
                if(cur!=nullptr){
                    stack.push(cur);
                    cur=cur->left;
                }
                else{
                    TreeNode* t=stack.top();
                    res.push_back(t->val);
                    stack.pop();
                    cur=t->right;
                }
            }
            return res;
        }
    };