class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j == t.size()) return 1; 
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0, nontake = 0;
        if (s[i] == t[j]) {
            take = solve(i + 1, j + 1, s, t, dp);
        }
        nontake = solve(i + 1, j, s, t, dp);

        return dp[i][j] = take + nontake;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t, dp);
    }
};