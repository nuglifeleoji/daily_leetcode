class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int left=1;
            int right=INT_MAX;
            while(left<right){
                int mid=left+(right-left)/2;
                if(check(mid, piles, h)){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return left;
        }
        bool check(int mid, vector<int>& piles, int h){
            int ans=0;
            for(int& g: piles){
                if(g% mid==0){
                    ans+=g/mid;
                }
                else{
                    ans+=g/mid+1;
                }
            }
            return ans<=h;
        }
    };