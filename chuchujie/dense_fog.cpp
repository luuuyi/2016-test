#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &res, int n){
	for(int i=0;i<n;i++){
		cout << res[i] << " ";
	}
	cout << endl;
}

void decode(string &s, int n, int cur, vector<bool>& marks, vector<int>& res, vector<vector<int>>& total){
	int lens = s.size();
	//本来这个位置应该记录所有可能的结果，但是题目的数据集只有唯一解，所以改进一下，记录所有解
	if(cur >= lens){
		//TODO
		total.push_back(res);
		return;
	}
	//因为n最大只有25，所以考虑步长为1和2的情况即可
	for(int k=1;k<=2;k++){
		int num = stoi(s.substr(cur, k));
		if(!(num>=1&&num<=n))	continue;
		if(!marks[num-1]){
			marks[num-1] = true;
			res.push_back(num);
			decode(s, n, cur+k, marks, res, total);
			res.pop_back();
			marks[num-1] = false;
		}
	}
}

//dfs解题，不过看评论貌似这道题如果用到一些数据集的话，答案是不唯一的
int main(){
	int n = 0;
	while(cin >> n){
		string s;
		cin >> s;
		vector<bool> marks(n, false);
		vector<int> res;
		vector<vector<int>> total;
		decode(s, n, 0, marks, res, total);
		printVec(total[0], n);
	}
	return 0;
}