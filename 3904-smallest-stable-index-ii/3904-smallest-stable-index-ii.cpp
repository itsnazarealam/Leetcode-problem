class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> pref (n,0);
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            pref[i] = maxi;
        }

        vector<int> suff (n,0);
        int mini = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            suff[i] = mini;
        }

        for(int i=0; i<n; i++){
            if(pref[i]-suff[i] <= k)
                return i;
        }

        return -1;
    }
};