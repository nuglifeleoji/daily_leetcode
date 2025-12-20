class Solution {
    public:
        int maxDistance(vector<int>& position, int m) {
            int left=1;
            sort(position.begin(), position.end());
            int right=position[position.size()-1]-position[0];
            while(left<right){
                int mid=left+(right-left+1)/2;
                if(check(position, m, mid)){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
            }
            return left;
        }
        bool check(vector<int>& position, int m, int mid){
            int previous=position[0];
            int count=1;
            for(int i=1;i<position.size();i++){
                if(position[i]>=mid+previous){
                    previous=position[i];
                    count++;
                    
                }
            }
            return count>=m;
        }
    };