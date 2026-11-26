class comp{
public:
    bool operator()(pair<int,int>& a, pair<int, int>& b){
        if(a.second==b.second)
            return a.first > b.first;

        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(auto& x : mp)
            pq.push({x.first, x.second});

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};