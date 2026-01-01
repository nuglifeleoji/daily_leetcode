class Solution {
    public:
        static bool compare(vector<int>& t1, vector<int>& t2){
            return t1[1]< t2[1];
        }
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            unordered_map<int, int> times;
            for(int g: arr){
                times[g]++;
            }
            vector<vector<int>> list;
            for(auto g: times){
                list.push_back({g.first, g.second});
            }
            sort(list.begin(), list.end(), compare);
            int cur=0;
            for(int i=0;i<list.size();i++){
                cur+=list[i][1];
                if(cur>k){
                    return list.size()-i;
                }
            }
            return 0;
        }
    };