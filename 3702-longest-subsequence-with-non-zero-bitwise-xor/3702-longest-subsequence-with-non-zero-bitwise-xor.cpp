class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int result = 0;
        bool allzero = true;
        int n = nums.size();

        for(auto &x : nums){
            result = result ^ x;

            if(x != 0)
                allzero = false;
        }
        if(allzero)
            return 0;
        
        return result==0 ? n-1 : n;
    }
};