class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int g=searchpeek(nums);
            int left1=0;
            int right1=g;
            int left2=g+1;
            int right2=nums.size()-1;
            while(left1<right1){
                int mid=left1+(right1-left1)/2;
                if(nums[mid]<target){
                    left1=mid+1;
                }
                else{
                    right1=mid;
                }
            }
            while(left2<right2){
                int mid=left2+(right2-left2)/2;
                if(nums[mid]<target){
                    left2=mid+1;
                }
                else{
                    right2=mid;
                }
            }
            if(left1<nums.size()){
                if(nums[left1]==target){
                    return left1;
                }
            }
            if(left2<nums.size()){
                if(nums[left2]==target){
                    return left2;
                }
            }
            return -1;
        }
        int searchpeek(vector<int>& nums){
           int left=0;
           int right=nums.size()-1;
           while(left<right){
                int mid=left+(right-left+1)/2;
                if(nums[mid]>=nums[left]){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
           } 
           return left;
        }
    };