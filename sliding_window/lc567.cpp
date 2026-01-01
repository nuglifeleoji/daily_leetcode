class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            unordered_map<char, int> map;
            for(char t: s1){
                map[t]++;
            }
            int l1=s1.size();
            unordered_map<char, int> cur;
            int match=0;
            for(int i=0;i<s2.size();i++){
                if(map.count(s2[i])){
                    cur[s2[i]]++;
                    if(cur[s2[i]]==map[s2[i]]){
                        match++;
                    }
                    if(cur[s2[i]]==map[s2[i]]+1){
                        match--;
                    }
                }
                if(i>=l1){
                    if(map.count(s2[i-l1])){
                        cur[s2[i-l1]]--;
                        if(cur[s2[i-l1]]==map[s2[i-l1]]){
                            match++;
                        }
                        if(cur[s2[i-l1]]==map[s2[i-l1]]-1){
                            match--;
                        }
                    }
                }
                if(match==map.size()){
                    return true;
                }
            }
            return false;
        }
    };