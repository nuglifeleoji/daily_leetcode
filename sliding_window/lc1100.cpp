class Solution {
    public:
        int numKLenSubstrNoRepeats(string s, int k) {
            unordered_map<char, int> map;
            int count=0;
            int ans=0;
            for(int i=0;i<s.size();i++){
                //add 
                map[s[i]]++;
                if(map[s[i]]==2){
                    count++;
                }
                if(i>=k){
                    map[s[i-k]]--;
                    if(map[s[i-k]]==1){
                        count--;
                    }
                }
                if(i>=k-1){
                    if(count==0){
                        ans++;
                    }
                }
            }
            return ans;
        }
    };