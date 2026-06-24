class Solution {
public:
    vector<int> leftSmaller(vector<int>& arr){
        vector<int> left(arr.size());
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> rightSmaller(vector<int>& arr){
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = leftSmaller(heights);
        vector<int> right = rightSmaller(heights);
        
        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};