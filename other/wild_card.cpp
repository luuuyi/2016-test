//正则匹配题目，注意和通配符匹配题目区别开来
class WildMatch {
public:
    bool chkWildMatch(string A, int lena, string B, int lenb) {
        // write code here
		vector<vector<bool>> dp(lena+1, vector<bool>(lenb+1, false));
		//初始化第一位和第一行的dp值
		dp[0][0] = true;
		for(int i=1;i<=lenb;i++){
			if(B[i-1] == '*')	dp[0][i] = dp[0][i-2];
		}
		//状态转移方程实现
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				//当前pattern为.或者对等字符时，对应的dp值为左上角的dp值
				if(B[j-1]=='.'||B[j-1]==A[i-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else if(B[j-1]=='*'){
					//当pattern为*的时候考虑两种情况
					//*表达为0，那就是取dp[i][j-2]的值，不需要解释
					//*表达为除了0外的任何值，前提是*之前的字符与当前待匹配的字符能够匹配
					//dp值为dp[i-1][j]
					dp[i][j] = (dp[i][j-2])||((A[i-1]==B[j-2]||B[j-2]=='.')&&dp[i-1][j]);
				}
				else{
					dp[i][j] = false;
				}
			}
		}
		return dp[lena][lenb];
    }
};