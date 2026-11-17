class Solution {
public:
    long long checkEating(vector<int>& piles, int m){
        long long count = 0;
        for(int i=0; i<piles.size(); i++){
            count += ceil((double)piles[i]/m);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        long long mini = INT_MAX;
        int e = *max_element(piles.begin(), piles.end());
        while(s<=e){
            long long mid = (s+e)/2;
            long long ans = checkEating(piles, mid);
            if(ans <= h){
                mini = min(mini, mid);
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return mini;
    }
};