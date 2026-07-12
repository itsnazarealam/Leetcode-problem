class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(int i=0; i<n; i++)
            pq.push({arr[i], i});

        vector<int> ans(n);
        int rank = 0;
        int prev = INT_MIN;
        while(!pq.empty()){
            int value = pq.top().first;
            int ind = pq.top().second;

            if(prev == value)
                ans[ind] = rank;
            else{
                rank++;
                ans[ind] = rank;
                prev = value;
            }
            pq.pop();
        }
        return ans;
    }
};