class Solution {
public:
    int m = 1e9+7;
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> nsl(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nsl;
    }
    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> nsr(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsr;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = getNSL(arr, n);
        vector<int> right = getNSR(arr, n);
        int sum = 0;
        for(int i=0; i<n; i++){

            int ls = i-left[i];
            int rs = right[i]-i;

            long long totalWays = ls*rs;
            long long totalSum = totalWays * arr[i];
            sum = (sum + totalSum)%m;
        }
        return sum;
    }
};