class Solution {
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k) {
            unordered_map<char, int> map;
            int slow=0;
            int max1=0;
            for(int i=0;i<s.size();i++){
                map[s[i]]++;
                while(map.size()>k){
                    map[s[slow]]--;
                    if(map[s[slow]]==0){
                        map.erase(s[slow]);
                    }
                    slow++;
                }
                max1=max(max1, i-slow+1);
            }
            return max1;
        }
    };