class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int left=0;
            int right=citations.size();
            while(left<right){
                int mid=left+(right-left+1)/2;
                if(check(citations, mid)){
                    left=mid;
                }
                else{
                    right=mid-1;
                }
            }
            return left;
        }
        bool check(vector<int>& citations, int mid){
            int s=citations.size()-1;
            return citations[s-mid+1]>=mid;
        }
    };