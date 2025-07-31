class Solution {
    private:
    int recurs(vector<int>& dp,vector<int>& nums,int ind){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

int pick = nums[ind]+recurs(dp,nums,ind-2);
int notPick = 0+recurs(dp,nums,ind-1);
return dp[ind]= max(pick , notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
if (n == 1) return nums[0];
        vector<int>temp1(nums.begin()+1,nums.end());
        vector<int>temp2(nums.begin(),nums.end()-1);

        vector<int>dp1(n-1,-1);
         vector<int>dp2(n-1,-1);

         int option1=recurs(dp1,temp1,n-2);
         int option2=recurs(dp2,temp2,n-2);

         return max(option1,option2);

     
    }
};