class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int leftSum = 0;
        for(int i=0; i<k; i++){
            leftSum += cardPoints[i];
        }
        cout<<leftSum;

        int maxSum = leftSum;
        int rightInd = n-1;

        for(int i=k-1; i>=0; i--){
            leftSum = leftSum - cardPoints[i] + cardPoints[rightInd--];
            maxSum = max(maxSum, leftSum);
        }

        return maxSum;
    }
};