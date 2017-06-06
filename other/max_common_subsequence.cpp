//最长公共子序列（经典题）
class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //状态转移方程，如果相等，则+1，不相等的话等于左边和上边值得最大值
                if(A[i-1] == B[j-1])    dp[i][j] = dp[i-1][j-1] + 1;
                else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};