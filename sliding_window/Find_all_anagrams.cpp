class Solution{
    public:
        vector<int> findAnagrams(string s, string p){
            vector<int> result;
            unordered_map<char, int> map;
            for(char c: p){
                map[c]++;
            }
            int n=map.size();
            int match=0;
            unordered_map<char, int> window;
            for(int fast=0;fast<s.size();fast++){
                //add
                if(map.count(s[fast])){
                    window[s[fast]]++;
                    if(window[s[fast]]==map[s[fast]]){
                        match++;
                    }
                    if(window[s[fast]]==map[s[fast]]+1){
                        match--;
                    }
                }
                //remove
                if(fast>=p.size()){
                    if(map.count(s[fast-p.size()])){
                        window[s[fast-p.size()]]--;
                        if(window[s[fast-p.size()]]==map[s[fast-p.size()]]){
                            match++;
                        }
                        if(window[s[fast-p.size()]]==map[s[fast-p.size()]]-1){
                            match--;
                        }
                    }
                }
                if(match==n){
                    result.push_back(fast-p.size()+1);
                }   
            }
            return result;
        }
}