class Solution {
    private:
 int recurs(vector<int>&temp,int i ,vector<int>& dp){
    if(i==0){
        return temp[i];
    }
    if(i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int pick =temp[i]+recurs(temp,i-2,dp);
    int notPick=0+recurs(temp,i-1,dp);
    return dp[i]=max(pick , notPick);
 }
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int>dp(n,-1);
vector<int>temp1(nums.begin(),nums.end()-1);
vector<int>temp2(nums.begin()+1,nums.end());
vector<int>dp1(n-1,-1);
vector<int>dp2(n-1,-1);
     int option1=recurs(temp1,n-2,dp1);
     int option2=recurs(temp2,n-2,dp2);

     return max(option1,option2);
    }
};