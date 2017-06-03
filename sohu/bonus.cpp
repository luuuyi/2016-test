#include <bits/stdc++.h>

using namespace std;

//方法：
//从前往后扫一遍，在从后往前扫一遍
int getMinBonus(const vector<int>& nums, int n){
	vector<int> pre(n, 1);
	vector<int> post(n, 1);
	//从前往后，物理意义，每个人只能看到左边比自己成绩小的人
	for (int i = 1; i<n; i++)	pre[i] = (nums[i]>nums[i - 1] ? pre[i - 1] + 1 : 1);
	//从后往前，物理意义，每个人只能看到右边比自己成绩小的人
	for (int i = n - 2; i >= 0; i--)	post[i] = (nums[i]>nums[i + 1] ? post[i + 1] + 1 : 1);
	int ret = 0;
	//统计两个数组中每个位置中所给奖金的最大值即可
	for (int i = 0; i<n; i++){
		ret += max(pre[i], post[i]);
	}
	return ret;
}

//要求在保持员工满意度之下的最小奖金总额
int main(){
	int n = 0;
	while (cin >> n){
		vector<int> nums(n, 0);
		for (int i = 0; i<n; i++)	cin >> nums[i];
		cout << getMinBonus(nums, n) << endl;
	}
	return 0;
}