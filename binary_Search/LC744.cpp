class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int left=0;
            int right=letters.size()-1;
            while(left<right){
                int mid=left+(right-left)/2;
                if((int)(letters[mid]-target)<=0){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            if((letters[right]-target)<=0){
                return letters[0];
            }
            return letters[right];
        }
    };