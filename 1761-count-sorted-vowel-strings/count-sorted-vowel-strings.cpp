class Solution {
public:
    int count(int n,int vo,vector<vector<int>> &dp)
    {
        if(n<=0)
        {
            return 1;
        }
        if(dp[n][vo] != -1)
        {
            return dp[n][vo];
        }
        int r=0;
        for(int j=vo;j>=1;j--)
        {
            r+=count(n-1,j,dp);
        }
        dp[n][vo]=r;
        return r;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(6,-1));
        return count(n,5,dp);
    }
};