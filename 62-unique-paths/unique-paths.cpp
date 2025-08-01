class Solution {
    private:
    int find(vector<vector<int>>&dp,int i , int j){
        if(i==0||j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up =find(dp,i-1,j);
        int left=find(dp,i,j-1);
        return dp[i][j]=(up+left);
    }
public:
 int uniquePaths(int m, int n) {
vector<vector<int>>dp(n,vector<int>(m,-1));
return find(dp,n-1,m-1);
       
    }
};