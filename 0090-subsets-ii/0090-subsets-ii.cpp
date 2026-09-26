class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>& nums, int i, vector<vector<int>>& output, vector<int>& ans){
        if(i==nums.size()){
            if(!st.count(ans)){
                st.insert(ans);
                output.push_back(ans);
            }
            return;
        }

        ans.push_back(nums[i]);
        solve(nums, i+1, output, ans);
        ans.pop_back();
        solve(nums, i+1, output, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> output;
        vector<int> ans;
        solve(nums, 0, output, ans);

        return output;
    }
};