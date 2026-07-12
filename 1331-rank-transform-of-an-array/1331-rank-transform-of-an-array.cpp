class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for(auto &x : st){
            mp[x] = rank++;
        }

        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};