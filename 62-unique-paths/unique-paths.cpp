
class Solution {
private:
  int recurs(vector<vector<int>>&dp,int i,int j){
        if(i==0 && j==0){
            return 1;
        }

        if(i<0||j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up=recurs(dp,i-1,j);
        int left=recurs(dp,i,j-1);
        return dp[i][j]=up+left;
         }
public:
    int uniquePaths(int m, int n) {
 vector<vector<int>>dp(m,vector<int>(n,-1));
 return recurs(dp,m-1,n-1);
    }
};