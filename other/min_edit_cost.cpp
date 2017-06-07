//编辑最小代价（经典题改编）
//最小代价的做法通不过oj
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //初始化dp数组第一列每一位
        for(int i=1;i<=n;i++)   dp[i][0] = i*c1;
        //初始化dp数组第一行每一位
        for(int i=1;i<=m;i++)   dp[0][i] = i*c0;
        //开始状态转移方程实现
        //等于则没有代价
        //不等于的话需要考虑比较多，主要是
        //min(上面，左面的最小值+c0, 删除再增加代价和直接替换代价的最小值+左上角)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1] == B[j-1])    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j-1]+min(c2, c0+c1), min(dp[i-1][j], dp[i][j-1])+c0);
                }
            }
        }
        return dp[n][m];
    }
};

//oj能通过的算法，但其实并不是最优解
class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //初始化dp数组第一列每一位
        for(int i=1;i<=n;i++)   dp[i][0] = i*c1;
        //初始化dp数组第一行每一位
        for(int i=1;i<=m;i++)   dp[0][i] = i*c0;
        //开始状态转移方程实现
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1] == B[j-1])    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j-1]+c2, min(dp[i-1][j]+c1, dp[i][j-1]+c0));
                }
            }
        }
        return dp[n][m];
    }
};