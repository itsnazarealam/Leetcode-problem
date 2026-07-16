class Solution {
public:
    bool isZero(vector<int>& arr, int i){
        if(i<0 || i>=arr.size() || arr[i]<0)
            return false;
            
        if(arr[i]==0)
            return true;

        arr[i] *= -1;

        bool a = isZero(arr, i+arr[i]);
        bool b = isZero(arr, i-arr[i]);
    
        return a||b;
    }
    bool canReach(vector<int>& arr, int start) {
        return isZero(arr, start);
    }
};