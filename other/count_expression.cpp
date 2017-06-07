//区间dp经典题
class Expression {
public:
    int countWays(string exp, int len, int ret) {
        // write code here
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(2, 0)));
        //首先枚举长度i
        for(int i=0;i<len;i+=2){
            //枚举起点j
            for(int j=0;j+i<len;j+=2){
                int ret0 = 0, ret1 = 0;
                //初始化当长度i等于0的情况
                if(i == 0){
                    dp[j][j+i][0] = ((exp[j]-'0')==0)?1:0;
                    dp[j][j+i][1] = ((exp[j]-'0')==1)?1:0;
                    //重要部分
                    continue;
                }
                //枚举中间点k
                for(int k=j;k<j+i;k+=2){
                    //t1代表左边部分结果为0的个数 * 右边部分结果为0的个数
                    //t2代表一边为1的个数 * 另一边为0的个数
                    //t3代表左边部分结果为1的个数 * 右边部分结果为1的个数
                    int t1 = (dp[j][k][0]%10007)*(dp[k+2][j+i][0]%10007);
                    int t2 = ((dp[j][k][0]%10007)*(dp[k+2][j+i][1]%10007) + (dp[j][k][1]%10007)*(dp[k+2][j+i][0]%10007))%10007;
                    int t3 = (dp[j][k][1]%10007)*(dp[k+2][j+i][1]%10007);
                    if(exp[k+1] == '&'){
                        ret0 += t1 + t2; ret1 += t3;
                    }
                    else if(exp[k+1] == '|'){
                        ret0 += t1; ret1 += t2 + t3;
                    }
                    else{
                        ret0 += t1 + t3; ret1 += t2;
                    }
                    ret0 %= 10007; ret1 %= 10007;
                }
                dp[j][j+i][0] = ret0;
                dp[j][j+i][1] = ret1;
            }
        }
        return dp[0][len-1][ret];
    }
};