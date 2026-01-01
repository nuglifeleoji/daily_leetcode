class Solution {
    public:
        int minDifference(vector<int>& nums) {
            if(nums.size()<=4) return 0;
            sort(nums.begin(), nums.end());
            int g=min(nums[nums.size()-4]-nums[0], nums[nums.size()-3]-nums[1]);
            int k=min(g, nums[nums.size()-2]-nums[2]);
            return min(k, nums[nums.size()-1]-nums[3]);
        }
    };