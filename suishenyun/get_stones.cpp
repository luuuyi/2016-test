//智商欠费，实在搞不懂
class Stones {
public:
    vector<int> result(int A, int B, int n, vector<int> e, vector<int> a) {
        // write code here
        const long long inf = 0x3f3f3f3f3f3f3f3f;
        vector<vector<long long>>dp(n + 1, vector<long long>(200, inf));
        int sum = 0, ans;
        dp[n][0] = -inf;
        for (int i = n - 1; i >= 0; i--){
            sum += a[i];
            for (int j = 0; j <= sum; j++){
                long long Achoose = -(dp[i + 1][sum - j + 1] - 1) - e[i];
                long long Apass = max(1ll, dp[i + 1][j] + (e[i] + 1));
                dp[i][j] = min(Achoose, Apass);
                if (i == 0 && dp[i][j] <= A - B)
                    ans = j;
            }
        }
        return vector<int>{ans, sum - ans};
    }
};