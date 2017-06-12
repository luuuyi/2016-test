#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

double getResult(vector<vector<double>>& persons, vector<int>& gifts, int N, int M){
	double ret = 0;
	for(int i=0;i<M;i++){
		//构建一个数组，记录当前礼物剩下多少个的概率
		vector<double> left(gifts[i]+1, 0);
		left[gifts[i]] = 1.0;
		//用每个人会选择当前礼物的概率来循环更新left数组的值
		for(int j=0;j<N;j++){
			//prob为会选择的概率，还剩k个物品的概率为：k+1个物品的概率*选择的概率 + k个物品的概率*不选择的概率
			double prob = persons[j][i];
			for(int k=0;k<=gifts[i];k++)	left[k] = (k+1>gifts[i]?0:left[k+1])*prob + left[k]*(1.0 - prob);
		}
		for(int j=0;j<=gifts[i];j++)	ret += j*left[j];
	}
	//计算出来的是还剩多少个礼物的期望，用总数相减即可得到分到礼物的人数的期望
	return N - ret;
}

//比较有难度的一个题，关于概率的题目
int main(){
	int N = 0, M = 0;
	while(cin >> N >> M){
		vector<vector<double>> persons(N, vector<double>(M, 0));
		vector<int> gifts(M, 0);
		//保存输入的数值
		for(int i=0;i<M;i++)	cin >> gifts[i];
		for(int i=0;i<N;i++)	for(int j=0;j<M;j++)	cin >> persons[i][j];
		//返回结果，保留小数点后一位
		cout << fixed << setprecision(1) << getResult(persons, gifts, N, M) << endl;
	}
	return 0;
}