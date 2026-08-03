class Solution {
public:
    int stoneScore(vector<int>& nums, int i, int n, vector<int>& dp){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        int result = INT_MIN;

        result = max(result, nums[i] - stoneScore(nums, i+1, n, dp));
        if(i+1 < n)
            result = max(result, nums[i]+nums[i+1] - stoneScore(nums, i+2, n, dp));
        if(i+2 < n)
            result = max(result, nums[i]+nums[i+1]+nums[i+2] - stoneScore(nums, i+3, n, dp));

        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp(n, -1);

        int val = stoneScore(stoneValue, 0, n, dp);
        if(val>0)
            return "Alice";
        else if(val<0)
            return "Bob";
        return "Tie";
    }
};