class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int max1=0;
            int slow=0;
            unordered_map<char, int> map;
            for(int i=0;i<s.size();i++){
                map[s[i]]+=1;
                if(map[s[i]]==2){
                    while(s[slow]!=s[i]){
                        map[s[slow]]--;
                        slow++;
                    }
                    map[s[slow]]--;
                    slow++;8
                }
                max1=max(max1, i-slow+1);
            }
            return max1;
        }
    };