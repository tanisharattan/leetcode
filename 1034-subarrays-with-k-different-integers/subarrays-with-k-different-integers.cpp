class Solution {
    private:
    int find(vector<int>&nums , int k){
           int n =nums.size();
           int left=0;
           int res=0;
           unordered_map<int,int>mapp;
           for(int right=0;right<n;right++){
                    mapp[nums[right]]++;
                    while(mapp.size()>k){
                        mapp[nums[left]]--;
                        if(mapp[nums[left]]==0){
                        mapp.erase(nums[left]);
                        }
                        left++;
                    }
                    res+=(right-left+1);
           }
           return res;
    }


public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return find(nums, k)-find(nums, k-1);
    }
};