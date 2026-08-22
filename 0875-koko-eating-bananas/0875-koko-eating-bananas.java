class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int s = 1;
        int e = Arrays.stream(piles).max().getAsInt();
        int ans = -1;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(checkFun(piles, mid, h) <= h){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
    private long checkFun(int[] arr, int t, int h){
        int count = 0;
        for(int i=0; i<arr.length; i++){
            count += Math.ceil((double)arr[i]/t);
            if(count > h)
                break;
        }
        return count;
    }
}