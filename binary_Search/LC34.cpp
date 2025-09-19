class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            if(nums.size()==0){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            int left1=0;
            int right1=nums.size()-1;
            while(left1<right1){
                int mid=left1+(right1-left1)/2;
                if(nums[mid]>=target){
                    right1=mid;
                }
                else{
                    left1=mid+1;
                }
            }
            if(nums[left1]!=target){
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            int left2=0;
            int right2=nums.size()-1;
            while(left2<right2){
                int mid=left2+(right2-left2+1)/2;
                if(nums[mid]<=target){
                    left2=mid;
                }
                else{
                    right2=mid-1;
                }
            }
            ans.push_back(left1);
            ans.push_back(left2);
            return ans;
        }
    };