class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
           deque<TreeNode*> dq;
           dq.push_back(root);
           vector<int> res;
           if(!root){
            return res;
           }
           while(dq.size()>0){
                int s=dq.size();
                for(int i=0;i<s;i++){
                    TreeNode* x=dq.front();
                    dq.pop_front();
                    if(x->left){
                        dq.push_back(x->left);
                    }
                    if(x->right){
                        dq.push_back(x->right);
                    }
                    if(i==s-1){
                        res.push_back(x->val);
                    }
                }
           }
           return res;
        }
    };