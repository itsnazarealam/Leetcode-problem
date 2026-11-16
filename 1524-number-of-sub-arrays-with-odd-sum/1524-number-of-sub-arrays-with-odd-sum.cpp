class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        
        int even = 1, odd = 0;
        int sum = 0, count = 0;

        for(int i=0; i<arr.size(); i++){
            sum += arr[i];

            if(sum%2==0){
                count = (count + odd) % m;
                even++;
            }
            else{
                count = (count + even) % m;
                odd++;
            }
        }
        return count;
    }
};