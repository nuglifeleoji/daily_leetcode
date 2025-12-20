class Solution{
    public:
        TreeNode* constructTree(vector<int>& level, vector<int>& inorder) {
            unordered_map<int, int> reverseIndex;
            for(int i=0;i<inorder.size();i++){
                reverseIndex[inorder[i]]=i;
            }
            return  construct(level,reverseIndex);
        }
        TreeNode* construct(vector<int>& level, unordered_map<int, int>& reverseIndex){
            if(level.empty()) return nullptr;
            int rootval=level[0];
            TreeNode* root=new TreeNode(rootval);
            vector<int> leftLevel, rightLevel;
            for(int i=1;i<level.size();i++){
                if(reverseIndex[level[i]]<reverseIndex[rootval]){
                    leftLevel.push_back(level[i]);
                }
                else{
                    rightLevel.push_back(level[i]);
                }
            }
            root->left=construct(leftLevel, reverseIndex);
            root->right=construct(rightLevel, reverseIndex);
            return root;
        }
    };
