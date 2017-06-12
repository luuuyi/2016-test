#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
	if(a[2] == b[2])	return a[1] > b[1];
	return a[2] > b[2];
}

int maxResult(vector<vector<int>>& persons, int n){
	sort(persons.begin(), persons.end(), cmp);
	vector<int> dp(n, 1);
	int max_val = 0;
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			//注意顺序，不然会造成逻辑断路
			//梳理一下，体重等于的情况下，只有身高相等才能叠，体重小于的情况下，身高不管相等还是小于的情况都能叠
			if((persons[i][2] <= persons[j][2] && persons[i][1] < persons[j][1])||(persons[i][2] == persons[j][2] && persons[i][1] == persons[j][1]))	dp[i] = max(dp[i], dp[j]+1);
		}
		max_val = max(max_val, dp[i]);
	}
	return max_val;
}

//主程序
int main(){
	int n = 0;
	while (cin >> n){
		vector<vector<int>> persons(n, vector<int>(3, 0));
		for(int i=0;i<n;i++)	cin >> persons[i][0] >> persons[i][1] >> persons[i][2];
		cout << maxResult(persons, n) << endl;
	}
	return 0;
}