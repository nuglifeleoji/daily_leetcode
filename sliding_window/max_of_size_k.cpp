class Solution{
    public:
        vector<int> MaxOfSizeK(vector<int>& nums, int k){
            deque<int> q;
            vector<int> result;
            for(int fast=0;fast<nums.size();fast++){
                if(fast>=k){
                    if(q.front()==fast-k){
                        q.pop_front();
                    }
                }
                while(!q.empty() && nums[q.back()]<nums[fast]){
                    q.pop_back();
                }
                q.push_back(fast);
                if(fast>=k-1){
                    result.push_back(nums[q.front()]);
                }
            }
            return result;
        }
}