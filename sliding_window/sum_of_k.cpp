class Solution{
    public:
        vector<int> SumOfK(vector<int>& nums, int k){
            vector<int> ans;
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=nums[i];
            }
            ans.push_back(sum);
            for(int i=k;i<nums.size();i++){
                sum+=nums[i]-nums[i-k];
                ans.push_back(sum);
            }
            return ans;
        }
}