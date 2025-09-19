class Solution {
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            int left=1;
            int right=1000000;
            while(left<right){
                int mid=left+(right-left)/2;
                if(check(mid, nums, threshold)){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return left;
        }
        bool check(int mid, vector<int>& nums, int threshold){
            int res=0;
            for(auto& k :nums){
                if(k%mid==0){
                    res+=k/mid;
                }
                else{
                    res+=k/mid+1;
                }
            }
            if(res<=threshold){
                return true;
            }
            else{
                return false;
            }
        }
    };