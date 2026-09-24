class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num>0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(digitSum(nums[i])==i)
                mini = min(mini, i);
        }
        return mini==INT_MAX ? -1 : mini;
    }
};