class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mapp;
        for( auto x: nums){
            mapp[x]++;
        }
        for( auto x: mapp){
            if(x.second>1){
                return x.first;
            }
        }
        return -1;
        }
};