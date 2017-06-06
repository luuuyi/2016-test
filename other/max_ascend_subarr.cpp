//最长递增子序列（经典题）
class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        //耗时的地方
        vector<int> dp(n+1, 1);
        //使用一个外部变量来维护最大值
        int max_val = 1;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>0;j--){
                //以A[i-1]结尾的子序列最大值能有多少
                if(A[i-1]>A[j-1])   dp[i] = max(dp[i], dp[j]+1);
            }
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};