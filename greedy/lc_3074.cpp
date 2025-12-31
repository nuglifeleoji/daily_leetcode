class Solution {
    public:
        int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
            sort(capacity.begin(), capacity.end());
            int sum=0;
            for(int g: apple){
                sum+=g;
            }
            int cur=0;
            for(int i=capacity.size()-1;i>=0;i--){
                cur+=capacity[i];
                if(cur>=sum){
                    return capacity.size()-i;
                }
            }
            return capacity.size();
        }
    };