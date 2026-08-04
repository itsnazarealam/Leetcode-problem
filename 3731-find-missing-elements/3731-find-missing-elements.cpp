class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> st;
        for(int x : nums)
            st.insert(x);

        vector<int> ans;
        int i=0;
        int count=*min_element(nums.begin(), nums.end());
        while(i<nums.size()){
            if(!st.count(count)){
                ans.push_back(count);
            }
            else
                i++;
            count++;
        }

        return ans;
    }
};