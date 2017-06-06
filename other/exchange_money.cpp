//用一个数组内的值组合成目标数
//和k-sum的题目有区别
//只要组成序列的某个元素个数不一样就可以看成不同的方法
//Method One
//二维数组辅助的dp（耗时耗空间）
class Exchange {
public:
    int countWays(vector<int> changes, int n, int x) {
        // write code here
		vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
		//初始化第一位
		dp[0][0] = 0;
		//changes的任何一个子序列组成0的方法都为1
		for(int i=1;i<=n;i++){
			dp[i][0] = 1;
		}
		//开始填值
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				//每一个位置的值等于0~i-1组成该值的方法数+0~i组成该值的方法数
				dp[i][j] = dp[i-1][j] + (j-changes[i-1]>=0?dp[i][j-changes[i-1]]:0);
			}
		}
		return dp[n][x];
    }
};

//本质上来说还是一个二维dp，不过用一个一维数组维护
//Method Two
class Exchange {
public:
    int countWays(vector<int> changes, int n, int x) {
        // write code here
		//优化之后的方法
		//开辟一个比较大的vector比较耗时
		vector<int> nums(x+1, 0);
		nums[0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=x;j++){
				//每一个位置的值等于0~i-1组成该值的方法数+0~i组成该值减去当前面额零钱结果的方法数
				nums[j] += (j-changes[i-1]>=0?nums[j-changes[i-1]]:0);
			}
		}
		return nums[x];
    }
};