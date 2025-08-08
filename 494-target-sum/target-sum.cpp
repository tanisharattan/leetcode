class Solution {
private:
    int countSubsets(vector<int> &nums, int sum, int n, vector<vector<int>> &dp) {
        if (n == 0) {
            if (sum == 0 && nums[0] == 0) return 2; 
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }
        if (dp[n][sum] != -1) return dp[n][sum];

        int notPick = countSubsets(nums, sum, n - 1, dp);
        int pick = 0;
        if (nums[n] <= sum) {
            pick = countSubsets(nums, sum - nums[n], n - 1, dp);
        }
        return dp[n][sum] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0)
            return 0;

        int sumS1 = (totalSum - target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(sumS1 + 1, -1));
        return countSubsets(nums, sumS1, nums.size() - 1, dp);
    }
};