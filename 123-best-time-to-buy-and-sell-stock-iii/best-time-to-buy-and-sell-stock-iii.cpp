class Solution {
    int find( vector<vector<vector<int>>> &dp , vector<int> &prices, int ind , int buy, int capacity ){
        int n = prices.size();
        if( ind==n|| capacity==0){
            return 0;
        }
        if(dp[ind][buy][capacity]!=-1){
            return dp[ind][buy][capacity];
        }
  if(buy){
    return dp[ind][buy][capacity]= max(-prices[ind]+find(dp , prices , ind+1,0, capacity), 0+find(dp , prices , ind+1 , 1, capacity));

  }
  else {
   return dp[ind][buy][capacity]=max(prices[ind]+find( dp , prices , ind+1 , 1 , capacity-1),0+find(dp , prices , ind+1 , 0 , capacity ));
  }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2 , vector<int>( 3 ,0)));

        for(int ind =n-1 ; ind>=0 ; ind--){
            for(int buy=0;buy<=1 ;buy++){
                for(int capacity =1;capacity<=2 ; capacity++){
                       if(buy){
     dp[ind][buy][capacity]= max(-prices[ind]+ dp[ind+1][0][capacity], 0+dp[ind+1][1][capacity]);

  }
  else {
    dp[ind][buy][capacity]=max(prices[ind]+dp[ind+1][1][capacity-1],0+dp[ind+1][0][capacity]);
  }
                }
            }
        }
 return dp[0][1][2];
    }
};