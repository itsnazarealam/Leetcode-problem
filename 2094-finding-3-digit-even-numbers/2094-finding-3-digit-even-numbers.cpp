class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        bool vis[1000]{};
        int n = digits.size();
        int num = 0;
        vector<int> ans;
        
        for(int i=0; i<n; i++){

            if(digits[i]==0)
                continue;

            for(int j=0; j<n; j++){
                if(i==j)
                    continue;

                for(int k=0; k<n; k++){
                    if(j==k || k==i || digits[k]%2 != 0)
                        continue;

                    num = digits[i]*100 + digits[j]*10 + digits[k];

                    if(!vis[num]){
                        vis[num] = true;
                        ans.push_back(num);
                    }
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};