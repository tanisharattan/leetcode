class Solution {
private:
    int find(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j) return 0;               // empty string
        if (i == j) return 1;               // single char is palindrome length 1

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = 2 + find(i + 1, j - 1, s, dp);
        } else {
            dp[i][j] = max(find(i + 1, j, s, dp), find(i, j - 1, s, dp));
        }

        return dp[i][j];
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return find(0, n - 1, s, dp);
    }
};
