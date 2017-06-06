//最长公共子串长度（经典题）
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int max_val = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //状态转移方程比较简单，相等的话就+1，否则为0
                if(A[i-1] == B[j-1])    dp[i][j] = dp[i-1][j-1] + 1;
                else    dp[i][j] = 0;
                //用一个外部变量来维护最大值
                max_val = max(max_val, dp[i][j]);
            }
        }
        return max_val;
    }
};