class Solution {

    private :
    int find( vector<int>&coins,vector<vector<int>>&dp, int ind , int amount  ){
        if (ind ==0 ){
            if ( amount%coins[0]==0)return amount/coins[ind];
            else return 1e9;
        }
        if (dp[ind][amount]!=-1){
            return dp [ind][amount];
        }

        int notPick = 0+find(coins , dp , ind-1, amount);
        int pick = INT_MAX;
        if(coins[ind]<=amount){
           pick=1+ find(coins, dp , ind ,amount-coins[ind]);
        }
        return dp [ind ][amount]= min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

       int ans =  find(coins , dp , n - 1, amount);
      if(ans>=1e9)
{
    return -1;
}
else return ans;
    }
};