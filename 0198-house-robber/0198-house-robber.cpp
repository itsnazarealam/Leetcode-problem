class Solution {
public:
    int robHouse(vector<int>& arr, int ind, vector<int>& dp){
        
        if(ind==0)      return arr[ind];
        if(ind<0)       return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        //pick
        int pick = arr[ind] + robHouse(arr, ind-2, dp);
        //not-pick
        int notpick = 0 + robHouse(arr, ind-1, dp);
        
        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robHouse(nums, n-1, dp);
    }
};