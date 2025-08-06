class Solution {

    int find(vector<vector<int>>&dp,int i ,vector<int>&nums,int target ){
        if(target==0){
            return true;
        }
         if (i < 0 || target < 0) return false;
       if(dp[i][target]!=-1){
        return dp[i][target];
       }
       int notPick=find(dp,i-1,nums,target);
int pick=false;
if(nums[i]<=target){
    pick = find(dp,i-1,nums,target-nums[i]);
}
return dp[i][target]=pick||notPick;

    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum=0;
      for(int i =0;i<n;i++){
         totalSum+=nums[i];
      }
      int sum=totalSum/2;

      if(totalSum%2!=0){
        return false;
      }

      vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
      return find(dp,n-1,nums,sum);
    }
};