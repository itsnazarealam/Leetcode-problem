class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        long long count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1 && row[i]>=2 && col[j]>=2)
                    count += ((row[i]-1)*(col[j]-1));
            }
        }
        return count;
    }
};