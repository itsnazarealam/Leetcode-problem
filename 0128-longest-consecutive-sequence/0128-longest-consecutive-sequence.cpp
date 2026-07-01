class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        sort(begin(nums), end(nums));

        int longest = 1;
        int count = 0, lastNum = INT_MIN;
        for(int i=0; i<n; i++){
            if(lastNum == nums[i]-1){
                count++;
                lastNum = nums[i];
            }
            else if(lastNum != nums[i]){
                count = 1;
                lastNum = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};