class Solution{
    private:
    int find(vector<int>& dp,vector<int>& nums,int i ){
        if(i==0){
            return nums[i];
        }
        if(i<0){
            return 0;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        int pick=nums[i]+find(dp,nums,i-2);
          int notPick=0+find(dp,nums,i-1);
          return dp[i]=max(pick,notPick);
        
    }
public:
    int rob(vector<int>& nums) {
int n = nums.size();
vector<int>dp(n,-1);
return find(dp,nums,n-1);

}
};

