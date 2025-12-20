class Solution {
    public TreeNode pruneTree(TreeNode root) {
       if(check(root)){
        return null;
       }
       else{
        root.left=pruneTree(root.left);
        root.right=pruneTree(root.right);
        return root;
       }

    }
    public boolean check(TreeNode root){
        if(root==null){
            return true;
        }
        if(root.val==1){
            return false;
        }
        else{
            return check(root.left)&&check(root.right);
        }
    }
}