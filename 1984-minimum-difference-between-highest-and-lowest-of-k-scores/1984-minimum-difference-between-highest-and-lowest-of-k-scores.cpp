class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));
        int mini=INT_MAX, maxi=INT_MIN;
        int n = nums.size();
        int i=0, j=0;
        int count = 0;
        int minEl = INT_MAX;

        while(j<n){
            count++;
            while(count==k){
                maxi = nums[k+i-1];
                mini = nums[i];
                minEl = min(abs(maxi-mini), minEl);
                count--;
                i++;
            }
            j++;
        }
        return minEl;
    }
};