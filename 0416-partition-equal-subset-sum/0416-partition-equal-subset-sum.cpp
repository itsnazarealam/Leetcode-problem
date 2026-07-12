class Solution {
public:
    bool partitionPossible(vector<int>& nums, int n, int target, vector<vector<int>>& dp){
        if(n<0)
            return false;
        if(target==0)
            return true;

        if(dp[n][target] !=-1)
            return dp[n][target];

        bool take = false;
        if(target>=nums[n])
            take = partitionPossible(nums, n-1, target-nums[n], dp);
        bool notTake = partitionPossible(nums, n-1, target, dp);

        return dp[n][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0)
            return false;
        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return partitionPossible(nums, n-1, target, dp);
    }
};