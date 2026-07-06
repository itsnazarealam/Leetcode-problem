class Solution {
public:
    int slidingWindow(string s, int k, char ch){
        int count=0;
        int n=s.size();
        int i=0, j=0;
        int maxi = 0;
        while(j<n){
            if(s[j] != ch)
                count++;
            if(count <= k){
                maxi = max(maxi, j-i+1);
            }
            else{
                while(i<=j && count > k){
                    if(s[i] != ch)
                        count--;
                    i++;
                }
            }
            if(count <= k){
                maxi = max(maxi, j-i+1);
            }
            j++;
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int trueCase = slidingWindow(answerKey, k, 'T');
        int falseCase = slidingWindow(answerKey, k, 'F');

        return max(trueCase, falseCase);
    }
};