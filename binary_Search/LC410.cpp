class Solution {
    public:
        int splitArray(vector<int>& nums, int k) {
            int left=0;
            int right=1e9;
            while(left<right){
                int mid=left+(right-left)/2;
                if(check(nums, mid, k)){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return left;
        }
        bool check(vector<int>& nums, int mid, int k){
            int cur=0;
            int cal=1;
            for(int g: nums){
                if(g>mid){
                    return false;
                }
                if(cur+g>mid){
                    cal+=1;
                    cur=g;
                }
                else{
                    cur+=g;
                }
            }
            return cal<=k;
        }
    };