class Solution {
public:
    int robHouse(vector<int>& arr, int n){
        int prev1 = arr[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += prev2;    //pick
            int notpick = prev1;  //not-pick
            
            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];

        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i != 0)  temp1.push_back(nums[i]);
            if(i != n-1)  temp2.push_back(nums[i]);
        }

        return max(robHouse(temp1, temp1.size()), robHouse(temp2, temp2.size()));
    }
};