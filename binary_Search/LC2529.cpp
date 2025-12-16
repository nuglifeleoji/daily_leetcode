class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int left=0;
            int right=nums.size()-1;
            while(left<right){
                int mid=left+(right-left+1)/2;
                if(nums[mid]<0){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
            }
            int left1=0;
            int right1=nums.size()-1;
            while(left1<right1){
                int mid=left1+(right1-left1)/2;
                if(nums[mid]>0){
                    right1=mid;
                }
                else{
                    left1=mid+1;
                }
            }
            if(nums[left]>=0){
                if(nums[left1]<=0){
                    return 0;
                }
                else{
                    return nums.size()-left1;
                }
            }
            else{
                if(nums[left1]<=0){
                    return left+1;
                }
                else{
                    return (nums.size() - left1 > left + 1) ? (nums.size() - left1) : (left + 1);
                }
            }
        }
    };