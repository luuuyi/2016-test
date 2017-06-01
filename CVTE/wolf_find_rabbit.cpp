#include <bits/stdc++.h>

using namespace std;

//第一次不隔位置查找，第二次隔一位查找，也就是x+2
//之后每一次都比前一次多隔一位查找
vector<bool> findRabbit(int x, int n){
	vector<bool> res(20, true);
	res[x] = false;
	for(int i=1;i<n;i++){
		x = (x+i+1) % 20;
		res[x] = false;
	}
	return res;
}

void printRes(vector<bool>& res){
	int count = 0;
	for(int i=0;i<20;i++){
		if(res[i]){
			count++;
			cout << i+1 << " ";
		}
	}
	if(count==0)	cout << -1;
	cout << endl;
}

//根据逻辑来判断了
int main(){
	int x = 0, n = 0;
	while(cin >> x >> n){
		vector<bool> res = findRabbit(x-1, n);
		printRes(res);
	}
	return 0;
}