class Solution {
    public:
        int maxCoins(vector<int>& piles) {
            sort(piles.begin(), piles.end());
            int sum=0;
            for(int i=piles.size()-1, k=0 ;k<piles.size()/3;i-=2, k++){
                sum+=piles[i-1];
            }
            return sum;
        }
    };