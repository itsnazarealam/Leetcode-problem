class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0; 
        for(int i=0; i<n; i++){
            int mul = 1;
            for(int j=i; j<n; j++){
                mul *= nums[j];
                if(mul < k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};