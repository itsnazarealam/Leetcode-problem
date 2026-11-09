class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return 0;
        
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i : nums){
            q.push(i);
            cout<<q.top()<<endl;
        }

        int count = 1;
        int maxi = 1;
        while(!q.empty()){
            int top = q.top();
            q.pop();
            if(top == q.top()-1)
                count++;
            else if(top == q.top())
                continue;
            else
                count = 1;
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};