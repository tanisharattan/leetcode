class Solution{

private:
int find(int ind,vector<int>& nums,vector<int>& dp){
     if (ind < 0) return 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int pick=find(ind-2,nums,dp)+abs(nums[ind]);
         int pick2=find(ind-1,nums,dp);

return dp[ind]=max(pick,pick2);
    }
    
public:
    int rob(vector<int>& nums) {
     int n =nums.size();

     vector<int>dp(n,-1);
     return find(n-1,nums,dp);
    }
};

