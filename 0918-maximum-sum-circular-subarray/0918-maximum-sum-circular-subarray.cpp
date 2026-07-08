class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
    int minSubArray(vector<int>& arr){
        int maxi = INT_MAX, sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            maxi = min(sum, maxi);
            if(sum>0)
                sum = 0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int maxSum = maxSubArray(nums);
        if(maxSum < 0)
            return maxSum;

        return max(total-minSubArray(nums), maxSum);
    }
};