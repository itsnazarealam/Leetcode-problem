class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for(auto x : nums)
            cnt[x]++;

        int ans = 0;
        if(cnt[1] % 2 == 0){
            ans = cnt[1]-1;
        }else{
            ans = cnt[1];
        }
        cnt.erase(1);
        for(auto &it: cnt){
            int num = it.first;
            int res = 0;
            long long x = num;

            while(cnt.find(x) != cnt.end() && cnt[x]>1){
                res += 2;
                x *= x;
            }
            if(cnt.find(x) != cnt.end()){
                ans = max(ans, res+1);
            }else{
                ans = max(ans, res-1);
            }
        }
        return ans;
    }
};