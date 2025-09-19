package dp;
public class lc312{
    public int maxCoins(int[] nums) {
        int[] newnums=new int[nums.length+2];
        newnums[0]=1;
        for(int i=1;i<=nums.length;i++){
            newnums[i]=nums[i-1];
        }
        newnums[nums.length+1]=1;
        int[][] dp=new int[nums.length+2][nums.length+2];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<dp[0].length;j++){
                dp[i][j]=0;
            }
        }
        for(int i=2;i<nums.length+2;i++){
            dp[i-2][i]=newnums[i-1]*newnums[i-2]*newnums[i];
        }
        for(int i=3;i<nums.length+2;i++){ 
            for(int j=i-2;j>=0;j--){
                for(int k=j+1; k<=i-1;k++){
                    dp[j][i]=Math.max(dp[j][i], dp[j][k]+dp[k][i]+newnums[i]*newnums[k]*newnums[j]);
                }
            }
        }
        return dp[0][nums.length+1];
    }
}