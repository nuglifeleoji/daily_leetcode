class Solution{
    public: 
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(root==nullptr){
                return false;
            }
            unordered_set<int> prefix;
            prefix.insert(0);
            return dfs(root, 0, targetSum, prefix);
        }
        bool dfs(TreeNode* root, int prev, int targetSum, unordered_set<int> &prefix){
            if(root==nullptr){
                return false;
            }
            int cursum=prev+root->val;
            if(prefix.count(cursum-targetSum)){
                return true;
            }
            bool Nonexist=(prefix.count(cursum)==0);
            prefix.insert(cursum);
            if(dfs(root->left, cursum, targetSum, prefix) || dfs(root->right, cursum, targetSum, prefix)){
                return true;
            }
            if(Nonexist){
                prefix.erase(cursum);
            }
            return false;
        }
}