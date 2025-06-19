int recurs(int ind ,vector<int>& nums, vector<int>& dp ){
 if(ind ==0){
    return nums[ind] ;
}
    if (ind < 0) return 0;

    if (dp[ind]!=-1){
        return dp[ind];
    }
   


int pick = nums[ind]+recurs(ind-2,nums,dp);
int notPick = 0+recurs(ind-1,nums,dp);
return dp[ind]= max(pick , notPick);

}


class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,-1);
           if (n == 1) return nums[0];
      
        vector<int> temp1(nums.begin() + 1, nums.end());     
        vector<int> temp2(nums.begin(), nums.end() - 1);     

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        int option1 = recurs(n - 2, temp1, dp1);
        int option2 = recurs(n - 2, temp2, dp2);

        return max(option1, option2);
    }
};