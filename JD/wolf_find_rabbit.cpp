//二维数组的dp经典题
//状态转移方程为：dp数组中每一个点值为左边和上边边的最大值+当前点的值
//dp[i][j] = board[i][j] + max(dp[i-1][j], dp[i][j-1]);
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
		int h = board.size(), w = board[0].size();
		vector<vector<int>> dp(h, vector<int>(w, 0));
		dp[0][0] = board[0][0];
		for(int i=1;i<h;i++)	dp[i][0] = board[i][0] + dp[i-1][0];
		for(int i=1;i<w;i++)	dp[0][i] = board[0][i] + dp[0][i-1];
		for(int i=1;i<h;i++){
			for(int j=1;j<w;j++){
				dp[i][j] = board[i][j] + max(dp[i-1][j], dp[i][j-1]);
			}
		}
		return dp[h-1][w-1];
    }
};