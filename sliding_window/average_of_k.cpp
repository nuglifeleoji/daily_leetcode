class Solution{
    public: 
        vector<double> AverageOfK(vector<int>& nums, int k){
            vector<double> ans;
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=nums[i];
            }
            ans.push_back(sum/k);
            for(int i=k;i<nums.size();i++){
                sum+=nums[i]-nums[i-k];
                ans.push_back(sum/k);
            }
        }
}