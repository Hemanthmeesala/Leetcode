class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[m-1][j] = mat[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int temp = dp[i+1][j];
                if(j>0){
                    temp = min(temp,dp[i+1][j-1]);
                }
                if(j<n-1){
                    temp = min(temp,dp[i+1][j+1]);
                }
                dp[i][j] = mat[i][j]+temp;
            }
        }

        int ans = INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;

    }
};