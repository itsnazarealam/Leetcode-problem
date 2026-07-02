class Solution {
public:
    int findPathSum(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(i<0 || j<0)
            return 1e9;
        if(i==0 && j==0)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = grid[i][j] + findPathSum(grid, i-1, j, dp);
        int left = grid[i][j] + findPathSum(grid, i, j-1, dp);

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findPathSum(grid, m-1, n-1, dp);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up=1e9, left=1e9;
                    if(i>0)
                        up = grid[i][j] + dp[i-1][j];
                    if(j>0)
                        left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};