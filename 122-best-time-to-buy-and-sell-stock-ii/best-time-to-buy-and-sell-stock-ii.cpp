class Solution {
    private:
    int find( vector<int>&prices ,vector<vector<int>>&dp , int ind , int buy  ){
        int n = prices.size();
        int profit=0;
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
     if (buy){
        profit = max(-prices[ind]+find(prices , dp ,ind+1,0),0+find(prices , dp ,ind+1,1));

     }
     else {
        profit = max(prices[ind]+find(prices, dp, ind+1 , 1),0+find(prices , dp ,ind+1,0));
     }
     return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp (n,vector<int> (2,-1));

        return find(prices , dp , 0 , 1);
    }
};