class Solution {
    public:
        bool isCompleteTree(TreeNode* root) {
            if(root==nullptr) return true;
            queue<TreeNode*> queue;
            queue.push(root);
            bool existNull=false;
            while(queue.size()>0){
                TreeNode* cur=queue.front();
                queue.pop();
                if(cur->left==nullptr){
                    existNull=true;
                }
                else{
                    if(existNull){
                        return false;
                    }
                    queue.push(cur->left);
                }
                if(cur->right==nullptr){
                    existNull=true;
                }
                else{
                    if(existNull){
                        return false;
                    }
                    queue.push(cur->right);
                }
            }
            return true;
        }
    };