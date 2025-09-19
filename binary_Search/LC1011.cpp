class Solution {
    public:
        int shipWithinDays(vector<int>& weights, int days) {
             long long left=0;
             long long right=INT_MAX;
             while(left<right){
                long long mid=left+(right-left)/2;
                if(check(mid, weights, days)){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
             }
             return (int)left;
        }
    bool check(long long mid, vector<int>& weights, int days){
        long long sum = 0;
        int need = 1;  // 至少需要一天
        for(int w : weights){
            if(w > mid) return false; // 单个包裹超过mid，不可能
            if(sum + w > mid){
                need++;
                sum = 0;
            }
            sum += w;
        }
        return need <= days;
    }
    };