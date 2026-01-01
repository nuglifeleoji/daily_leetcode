class Solution {
    public:
        int minIncrementForUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int prev=nums[0];
            int sum=0;
            for(int i=1;i<nums.size();i++){
                sum+=max(prev+1-nums[i], 0);
                prev=max(prev+1, nums[i]);
            } 
            return sum;
        }
    };