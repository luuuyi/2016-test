//区间dp经典题
class Cards {
public:
    int cardGame(vector<int> A, int n) {
        // write code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        //枚举长度i
        for(int i=0;i<n;i++){
            //枚举起点j
            for(int j=0;j+i<n;j++){
                //当长度i为0的时候更新初始值
                if(i == 0){
                    dp[j][j+i][0] = A[j];
                    continue;
                }
                //每一次用0表示先手，1表示后手
                //先手肯定选择两端其中一个值和剩下区间值后手之和的最大值
                //后手就只能选择区间值先手的值，没有商量的余地
                if(A[j]+dp[j+1][j+i][1] > A[j+i]+dp[j][j+i-1][1]){
                    dp[j][j+i][0] = A[j]+dp[j+1][j+i][1];
                    dp[j][j+i][1] = dp[j+1][j+i][0];
                }
                else{
                    dp[j][j+i][0] = A[j+i]+dp[j][j+i-1][1];
                    dp[j][j+i][1] = dp[j][j+i-1][0];
                }
            }
        }
        //最终返回先手或者后手里面最大的那个值
        return max(dp[0][n-1][1], dp[0][n-1][0]);
    }
};