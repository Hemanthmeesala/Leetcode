class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                if(i == n-1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int down = dp[i+1][j] + triangle[i][j];
                int diagonal = dp[i+1][j+1] + triangle[i][j];

                dp[i][j] = min(down, diagonal);
            }
        }
        return dp[0][0];
    }
};