class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int leftMul = 1, rightMul = 1;

        for(int i=0; i<n; i++){
            if(leftMul==0)  leftMul = 1;
            if(rightMul==0)  rightMul = 1;

            leftMul *= nums[i];
            rightMul *= nums[n-i-1];

            maxi = max(maxi, max(leftMul, rightMul));
        }
        return maxi;
    }
};