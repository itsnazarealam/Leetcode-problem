class Solution {
public:
    int minCoins(vector<int>& coins, int target, int ind, vector<vector<int>>& dp){
        if(ind==0){
            if(target % coins[ind] == 0)
                return target/coins[0];
            else
                return 1e9;
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = 0 + minCoins(coins, target, ind-1, dp);

        int take = INT_MAX;
        if(coins[ind] <= target)
            take = 1 + minCoins(coins, target-coins[ind], ind, dp);

        return dp[ind][target] = min(take,notTake);        
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = minCoins(coins, amount, n-1, dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};