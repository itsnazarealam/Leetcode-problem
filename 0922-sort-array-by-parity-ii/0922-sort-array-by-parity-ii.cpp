class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int i=0, even=0, odd=1;
        int n = nums.size();
        vector<int> ans(n);
        while(i<n){
            if(nums[i]%2==0){
                ans[even] = nums[i];
                even += 2;
            }
            else{
                ans[odd] = nums[i];
                odd += 2;
            }
            i++;
        }
        return ans;
    }
};