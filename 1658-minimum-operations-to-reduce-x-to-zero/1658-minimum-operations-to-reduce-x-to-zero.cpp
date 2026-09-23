class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = accumulate(begin(nums), end(nums), 0);
        int target = total-x;
        
        int n = nums.size();
        int i=0, j=0;
        int sum=0;
        int maxLen  = -1;

        while(j<n){

            sum += nums[j];
            while (sum > target && i<=j) {
                sum -= nums[i];
                i++;
            }
            if(sum==target)
                maxLen  = max(maxLen , j-i+1);

            j++;
        }
        if(target==0)
            return n;

        if(maxLen == -1)
            return -1;
        return n-maxLen;
    }
};