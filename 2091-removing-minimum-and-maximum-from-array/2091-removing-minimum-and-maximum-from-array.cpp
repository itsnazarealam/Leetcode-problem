class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int miniInd = min_element(begin(nums), end(nums)) - begin(nums);      
        int maxiInd = max_element(begin(nums), end(nums)) - begin(nums);
          
        int left = min(miniInd, maxiInd);
        int right = max(miniInd, maxiInd);
    
        return min({left+1+n-right, right+1, n-left});
    }
};