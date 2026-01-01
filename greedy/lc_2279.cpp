class Solution {
    public:
        int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
            vector<int> g;
            for(int i=0;i<capacity.size();i++){
                g.push_back(capacity[i]-rocks[i]);
            }
            sort(g.begin(), g.end());
            int cur=0;
            for(int i=0;i<g.size();i++){
                cur+=g[i];
                if(cur>additionalRocks){
                    return i;
                }
            }
            return g.size();
        }
    };