class Solution {
    public:
        int findMin(vector<int>& nums) {
            if(nums.size()==1){
                return nums[0];
            }
            int left=0;
            int right=nums.size()-1;
            while(right>=0 && nums[right]==nums[0]){
                right--;
            }
            int k=right;
            while(left<right){
                int mid=left+(right-left)/2;
                if(nums[mid]<nums[0]){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            if(left==nums.size()-1 || left==k){
                return nums[0]<=nums[left]?nums[0]:nums[left];
            }
            return nums[left];
        }
    };