//字符串交错组成，dp经典题
class Mixture {
public:
    bool chkMixture(string A, int n, string B, int m, string C, int v) {
        // write code here
        if(n+m != v)    return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        for(int i=1;i<=n;i++){
            if(A[i-1] == C[i-1])    dp[i][0] = true;
            else    break;
        }
        for(int i=1;i<=m;i++){
            if(B[i-1] == C[i-1])    dp[0][i] = true;
            else    break;
        }
        //状态转移方程实现
        //判断C[i+j-1]是否与A[i-1]或者B[j-1]相同，然后跟相应的状态做与运算
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = (C[i+j-1]==A[i-1] && dp[i-1][j]) || (C[i+j-1]==B[j-1] && dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};