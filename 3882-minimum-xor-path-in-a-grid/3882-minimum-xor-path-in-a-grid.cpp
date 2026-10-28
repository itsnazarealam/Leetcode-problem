class Solution {
public:
    int mini = INT_MAX;
    void solve(vector<vector<int>>& grid, int i, int j, int sum, vector<vector<vector<bool>>>& dp){
        if(i==0 && j==0){
            sum = sum^grid[i][j];
            mini = min(mini, sum);
            return;
        }

        if(i<0 || j<0)
            return;

        if(dp[i][j][sum])
            return;

        dp[i][j][sum] = true;

        sum ^= grid[i][j];

        solve(grid, i-1, j, sum, dp);
        solve(grid, i, j-1, sum, dp);
    }
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n,vector<bool>(1024, false)));

        solve(grid, m-1, n-1, 0, visited);
        
        return mini;
    }
};