class Solution {
private:
int find( string&s, vector<vector<int>>&dp , int i , int j){
    if(i==j){
        return 1;
    }

    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];

    }

    if(s[i]==s[j]){
        return dp[i][j]=2+find(s, dp , i+1,j-1);
    }
    return dp[i][j]=max(find(s , dp , i+1, j), find(s,dp,i,j-1));
}

public:
    int minInsertions(string s) {
       int n = s.length();
       vector<vector<int>>dp(n,vector<int>(n,-1));

      return n - find( s , dp , 0 , n-1);
    }
};
