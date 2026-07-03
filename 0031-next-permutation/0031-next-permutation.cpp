class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                pivot = i-1;
                break;
            }
        }
        if(pivot != -1){
            int swap_ind = pivot;
            for(int i=n-1; i>=pivot+1; i--){
                if(nums[pivot] < nums[i]){
                    swap_ind = i;
                    break;
                }
            }
            swap(nums[pivot], nums[swap_ind]);
        }
        reverse(nums.begin()+1+pivot, nums.end());
    }
};