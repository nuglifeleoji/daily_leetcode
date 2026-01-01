class Solution{
    public: 
        vector<int> ProductOfK(vector<int>& nums, int k){
            vector<int> result;
            int zerocount=0;
            int product=1;
            for(int fast=0;fast<nums.size();fast++){
                if(nums[fast]==0){
                    zerocount++;
                }
                else{
                    product*=nums[fast];
                }
                if(fast>=k){
                    int to_remove=nums[fast-k];
                    if(to_remove==0){
                        zerocount--;
                    }
                    else{
                        product/=to_remove;
                    }
                }
                if(fast>=k-1){
                    if(zerocount==0){
                        result.push_back(product);
                    }
                    else{
                        result.push_back(0);
                    }
                }
            }
            return result;
        }
    }