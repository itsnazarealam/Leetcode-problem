class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){

            stack<int> st;
            for(int j=nums2.size()-1; j>=0; j--){
                
                if(nums1[i]==nums2[j]){
                    while(!st.empty() && st.top() < nums1[i])
                        st.pop();

                    if(!st.empty() && nums1[i] < st.top())
                        ans[i] = st.top();
                    else
                        ans[i] = -1;
                    break;
                }
                st.push(nums2[j]);
            }
        }
        return ans;

    }
};