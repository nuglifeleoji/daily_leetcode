class Solution {
    public:
        unordered_map<char, int> map;
        vector<string> findRepeatedDnaSequences(string s) {
            map['A']=0;
            map['C']=1;
            map['G']=2;
            map['T']=3;
            unordered_set<string> res;
            unordered_set<int> set;
            vector<string> ans;
            int sum=0;
            for(int i=0;i<s.size();i++){
                if(i>=10){
                    sum-=map[s[i-10]]*pow(4, 9);
                }
                sum*=4;
                sum+=map[s[i]];
                if(i>=9){
                    if(set.count(sum)){
                        res.insert(s.substr(i-9, 10));
                    }
                    set.insert(sum);
                }
            }
            for(string t: res){
                ans.push_back(t);
            }
            return ans;
        }
    };