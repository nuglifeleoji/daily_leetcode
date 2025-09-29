class Solution {
    HashMap<Integer, Integer> map=new HashMap<>();
    int times=0;
    int sum=0;
    public int pseudoPalindromicPaths (TreeNode root) {
        dfs(root);
        return sum;
    }
    public void dfs(TreeNode root){
        if(root==null){
            return;
        }
        else{
            map.put(root.val,map.getOrDefault(root.val,0)+1);
            if(map.get(root.val)%2==1){
                times++;
            }
            else{
                times--;
            }
            if(root.left==null&&root.right==null){
                if(times==0||times==1){
                    sum++;
                }
            }
            dfs(root.left);
            dfs(root.right);
            map.put(root.val, map.get(root.val)-1);
            if(map.get(root.val)%2==1){
                times++;
            }
            else{
                times--;
            }
            return;
        }
    }
}