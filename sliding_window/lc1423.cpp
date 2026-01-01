class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int total=0;
            for(int g: cardPoints){
                total+=g;
            }
            int s=cardPoints.size()-k;
            if(s==0){
                return total;
            }
            int min1=INT_MAX;
            int cur=0;
            for(int i=0;i<cardPoints.size();i++){
                cur+=cardPoints[i];
                if(i>=s){
                    cur-=cardPoints[i-s];
                }
                if(i>=s-1){
                    min1=min(min1, cur);
                }
            }
            return total-min1;
        }
    };