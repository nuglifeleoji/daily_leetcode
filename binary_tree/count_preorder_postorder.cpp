class Solution{
    public:
        unordered_map<int, int> reversePre;
        unordered_map<int, int> reversePost;
        countNumber(vector<int>& preorder, vector<int>& postorder) {
            for(int i=0;i<postorder.size();i++){
                reversePost[postorder[i]]=i;
                reversePre[preorder[i]]=i;
            }
            return count(preorder, 0, preorder.size()-1, 0, postorder.size()-1);
        }
        int count(vector<int>& preorder, int preStart, int preEnd, int postStart, int postEnd){
            if(preStart>preEnd || postStart>postEnd){
                return 0;
            }
            if(preStart==preEnd && postStart==postEnd){
                return 1;
            }
            if(preorder[preStart+1]==postorder[postEnd-1]){
                return 2*count(preorder, preStart+1, preEnd, postStart, postEnd-1);
            }
            else{
                int l1=reversePre[postorder[postEnd-1]];
                int l2=reversePost[preorder[preStart+1]];
                int left=count(preorder, preStart+1, l1-1, postStart, l2);
                int right=count(preorder, l1, preEnd, l2+1, postEnd-1);
                return left*right;
            }
        }
}