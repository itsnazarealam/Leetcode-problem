class Solution {
public:
    int stoneScore(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        if(dp[i][j] != -1)
            return dp[i][j];

        int take_i = nums[i] - stoneScore(nums, i+1, j, dp);
        int take_j = nums[j] - stoneScore(nums, i, j-1, dp);

        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return stoneScore(piles, 0, n-1, dp) >= 0;
    }
};