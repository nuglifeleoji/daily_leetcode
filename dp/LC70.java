package dp;

public class LC70 {
    public int climbStairs(int n) {
        int[] list=new int[n];
        list[0]=1;
        if(n==1){
            return 1;
        }
        list[1]=2;
        for(int i=2;i<n;i++){
            list[i]=list[i-1]+list[i-2];
        }
        return list[n-1];
    }
}