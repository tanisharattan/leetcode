class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi =0;
        int left = 0 ;
        int right=0;
       int zeros=0;
while(right<n){
    if(nums[right]==0){
        zeros++;
    }
    while(k<zeros){
        if(nums[left]==0){
            zeros--;
        }
            left++;
    }
     maxi=max(maxi,right-left+1);
     right++;
}
return maxi;
    }
};