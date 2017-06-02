#include <bits/stdc++.h>

using namespace std;

int getResult(string& s){
	sort(s.begin(), s.end());
	priority_queue<int, vector<int>, greater<int>> pri_que;
	int lens = s.size();
	int cnt = 0;
	//用一个优先队列来维护每个字符的词频
	for(int i=0, j=0;i<lens;){
		j = i;
		while(j<lens-1&&s[j]==s[j+1])	++j;
		pri_que.push(j-i+1);
		i = j + 1; cnt++;
	}
	int ret = 0;
	//计算每一个非叶节点的权值之和
	for(int i=0;i<cnt-1;i++){
		int A = pri_que.top(); pri_que.pop();
		int B = pri_que.top(); pri_que.pop();
		ret += A+B;
		pri_que.push(A+B);
	}
	return ret;
}

//可以得知，哈夫曼树的带权路径长度等于哈夫曼树中非叶节点的权值之和；
//所以可以用一个优先队列来维护字符串中每个字符的出现频次；
int main(){
	string s;
	while(cin >> s){
		cout << getResult(s) << endl;
	}
	return 0;
}