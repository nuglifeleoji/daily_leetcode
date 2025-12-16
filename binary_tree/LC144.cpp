class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            if(root==nullptr){
                return res;
            }
            stack<TreeNode*> stack;
            res.push_back(root->val);
            if(root->right!=nullptr) stack.push(root->right);
            if(root->left!=nullptr) stack.push(root->left);
            while(stack.size()!=0){
                TreeNode* cur=stack.top();
                stack.pop();
                res.push_back(cur->val);
                if(cur->right!=nullptr) stack.push(cur->right);
                if(cur->left!=nullptr) stack.push(cur->left);
            }
            return res;
        }
    };