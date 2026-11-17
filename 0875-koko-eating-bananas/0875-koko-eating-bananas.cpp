class Solution {
public:
    long long findMin(vector<int>& arr, int d){
        long long count = 0;
        for(int i=0; i<arr.size(); i++){
            count += ceil((double)arr[i]/d);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *max_element(piles.begin(), piles.end());
        long long mini = INT_MAX;
        while(l<=r){
            long long mid = l+(r-l)/2;
            long long ans = findMin(piles, mid);
            if(ans <= h){
                mini = min(mini, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return mini;
    }
};