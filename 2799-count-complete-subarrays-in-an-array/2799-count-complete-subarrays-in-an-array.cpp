class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int x : nums)
            mp[x]++;

        int sz = mp.size();
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            unordered_map<int, int> mp2;
            for(int j=i; j<n; j++){
                mp2[nums[j]]++;
                if(mp2.size()==sz){
                    count++;
                }
                else if(mp2.size()>sz)
                    break;
            }
        }
        return count;
    }
};