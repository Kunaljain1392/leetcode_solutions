class Solution {
public:
    int solve(string& s, string& t, int n, int m, vector<vector<int>>& dp) {

        if (m < 0) {
            return 1;
             
        }
        if (n < 0) {
            
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (s[n] == t[m]) {
            dp[n][m] = solve(s,t,n-1,m-1,dp) + solve(s, t, n - 1, m, dp);
            return dp[n][m];
        } else {
            return solve(s, t, n - 1, m, dp);
        }

        return -1;
    }

    int numDistinct(string s, string t) {
        int n = s.length() - 1;
        int m = t.length() - 1;

        vector<vector<int>> dp(1001, vector<int>(1001, -1));

        return solve(s, t, n, m, dp);
    }
};