class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int mini=INT_MAX, maxi=INT_MIN;
        int n = nums.size();
        int i=0, j=0;
        int count = 0;
        vector<int> arr;
        int minEl = INT_MAX;

        while(j<n){
            count++;
            arr.push_back(nums[j]);
            while(count==k){
                maxi = arr[k+i-1];
                mini = arr[i];
                minEl = min(abs(maxi-mini), minEl);
                count--;
                i++;
            }
            j++;
        }
        return minEl;
    }
};