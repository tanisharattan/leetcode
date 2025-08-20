class Solution {
    private:
    int solve( int i , int j, vector<vector<int>>& matrix, vector<vector<int>>& dp , int &total){
       
        if(i<0 || j<0){
            return 0;
        }
        if(matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = solve(i-1, j, matrix , dp,total);
        int down =solve(i, j-1,matrix , dp,total);
        int diagonal= solve(i-1 , j-1, matrix , dp,total);
    dp[i][j]=min({up ,diagonal , down})+1;
total +=dp[i][j];
return dp[i][j];
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int total=0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n , vector<int>(m,-1));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
        
        solve(i , j, matrix , dp, total);
            }
        }
        return total;
    }
};