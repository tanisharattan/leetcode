class Solution {
    int find ( string&word1 , string&word2 , int i , int j , vector<vector<int>>&dp){
        if(i<0 || j<0 ){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j]= 1+find(word1 , word2 , i-1 , j-1 , dp);
        }
        return dp[i][j]=max(find(word1, word2 , i-1,j,dp),find(word1 , word2 , i , j-1,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m =word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        int l =find (word1,word2 , n-1 , m-1, dp);
        return (n-l)+(m-l);
    }
};