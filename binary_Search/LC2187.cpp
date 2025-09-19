class Solution {
    public:
        long long minimumTime(vector<int>& time, int totalTrips) {
            long long left=0;
            long long right=LLONG_MAX;
            while(left<right){
                long long mid=left+(right-left)/2;
                if(check(time,mid, totalTrips)){
                   right=mid;
                }
                else{
                    left=mid+1;
                }
            }
            return left;
        }
        bool check(vector<int>& time, long long mid, int totalTrips){
            long long ans=0;
            for(auto& t: time){
                ans+=mid/(long long)t;
                if(ans >= totalTrips) return true;
            }
            if(ans>=totalTrips){
                return true;
            }
            return false;
        }
    };