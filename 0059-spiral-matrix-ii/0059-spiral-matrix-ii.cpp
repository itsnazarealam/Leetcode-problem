class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> output(n, vector<int>(n));
        int count = 1;

        int startRow=0, startCol=0, endRow=n-1, endCol=n-1;

        while(count <= n*n){

            for(int i=startCol; i<=endCol; i++){
                output[startRow][i] = count;
                count++;
            }
            startRow++;

            for(int i=startRow; i<=endRow; i++){
                output[i][endCol] = count;
                count++;
            }
            endCol--;

            for(int i=endCol; i>=startCol; i--){
                output[endRow][i] = count;
                count++;
            }
            endRow--;

            for(int i=endRow; i>=startRow; i--){
                output[i][startCol] = count;
                count++;
            }
            startCol++;

        }
        return output;
    }
};