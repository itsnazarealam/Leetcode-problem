class Solution {
public:
    int noOfWays(int amount, vector<int>& coins, int n, vector<vector<int>>& dp){
        if(amount==0)
            return 1;
        if(amount < 0)
            return 0;
        if(n<0)
            return 0;
        if(dp[n][amount] != -1)
            return dp[n][amount];

        int take = noOfWays(amount-coins[n], coins, n, dp);
        int notTake = noOfWays(amount, coins, n-1, dp);

        return dp[n][amount] = (take+notTake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return noOfWays(amount, coins, n-1, dp);
    }
};