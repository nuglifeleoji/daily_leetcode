class Solution {
    public:
        int minDeletions(string s) {
            unordered_map<char, int> map;
            for(char t: s){
                map[t]++;
            }
            vector<int> list;
            for(auto& s: map){
                list.push_back(s.second);
            }
            sort(list.begin(), list.end());
            int sum=0;
            int prev=list[list.size()-1];
            for(int i=list.size()-2;i>=0;i--){
                sum+=max(0, list[i]-max((prev-1), 0));
                prev=min(max(prev-1, 0), list[i]);
            }
            return sum;
        }
    };