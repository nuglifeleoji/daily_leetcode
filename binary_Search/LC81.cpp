class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int left=0;
            int right=nums.size()-1;
            while(left<right){
                int mid=left+(right-left)/2;
                if(nums[mid]>nums[right]){
                    if(target==nums[mid]){
                        return true;
                    }
                    else if(target<nums[mid]&&target>=nums[0]){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
                else if(nums[mid]<nums[right]){
                    if(target==nums[mid]){
                        return true;
                    }
                    if(target>=nums[mid]&&target<=nums[right]){
                        left=mid+1;
                    }
                    else{
                        right=mid;
                    }
                }
                else{
                    if(nums[mid]==target){
                        return true;
                    }
                    right--;
                }
            }
            return nums[left]==target;
        }
    };