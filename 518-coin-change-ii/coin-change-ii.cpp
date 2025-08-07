class Solution {
    private:
    int find( vector<vector<int>>&dp, vector<int>&coins, int amount , int ind){
        if(ind==0){
            return amount%coins[0]==0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int notTake= find(dp , coins , amount , ind-1);
        int take=0;
        if(coins[ind]<=amount){
            take = find(dp ,coins , amount -coins[ind], ind);

        }
        return dp[ind][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find ( dp , coins , amount , n-1);
    }
};