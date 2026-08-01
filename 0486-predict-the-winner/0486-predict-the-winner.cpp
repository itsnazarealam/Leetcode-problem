class Solution {
public:
    int calSum(vector<int>& nums, int i, int j){
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];

        int take_i = nums[i] + min(calSum(nums, i+2, j), calSum(nums, i+1, j-1));
        int take_j = nums[j] + min(calSum(nums, i, j-2), calSum(nums, i+1, j-1));

        return max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        int total = accumulate(begin(nums), end(nums), 0);
        int p1 = calSum(nums, 0, n-1);
        int p2 = total - p1;
        
        return p1 >= p2;
    }
};