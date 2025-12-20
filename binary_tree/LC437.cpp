class Solution {
    public:
        int times=0;
        int pathSum(TreeNode* root, int targetSum) {
            unordered_map<long long, int> prefixSums;
            prefixSums[0]=1;
            dfs(root, targetSum, 0, prefixSums);
            return times;
        }
        void dfs(TreeNode* root, int targetSum, long long prev, unordered_map<long long, int>& prefix){
            if(root==nullptr) return;
            long long cur=prev+root->val;
            times+=prefix[cur-targetSum];
            prefix[cur]++;
            dfs(root->right, targetSum, cur, prefix);
            dfs(root->left, targetSum, cur, prefix);
            prefix[cur]--;
            if(prefix[cur]==0){
                prefix.erase(cur);
            }
        }
    };