class Solution {
    public:
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
            set<int> window;
            for(int i=0;i<nums.size();i++){
                auto it=window.upper_bound(nums[i]);
                //找到小于等于
                if(it!=window.begin()){
                    it--;
                    if((long long)nums[i]-*it<=valueDiff){
                        return true;
                    }
                }
                it=window.lower_bound(nums[i]);
                //找到大于等于
                if(it!=window.end() && (long long)*it- nums[i]<=valueDiff){
                    return true;
                }
                window.insert(nums[i]);
                if(i>=indexDiff){
                    window.erase(nums[i-indexDiff]);
                }
            }
            return false;
        }
    };