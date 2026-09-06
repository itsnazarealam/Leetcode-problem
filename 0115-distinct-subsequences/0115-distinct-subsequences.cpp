class Solution {
public:
    typedef unsigned long long ull;

    ull countDistinct(string s, string t, int m, int n, vector<vector<ull>>& dp){
        if(n==0)
            return dp[m][n] = 1;
        if(m==0)
            return dp[m][n] = 0;

        if(dp[m][n] != -1)
            return dp[m][n];

        if(s[m-1] == t[n-1])
            return dp[m][n] = countDistinct(s, t, m-1, n-1, dp) + countDistinct(s, t, m-1, n, dp);
        else
            return dp[m][n] = countDistinct(s, t, m-1, n, dp);
    }
    int numDistinct(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<vector<ull>> dp(m+1, vector<ull>(n+1, -1));

        return countDistinct(s, t, m, n, dp);
    }
};