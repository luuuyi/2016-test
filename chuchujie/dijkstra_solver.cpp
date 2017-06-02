#include <bits/stdc++.h>
//#define INT_MAX 0X7fffffff
using namespace std;

//dijkstra函数主体
void dijkstraSolver(const vector<int>& weights, const vector<vector<int>>& marks, vector<bool>& is_visited, vector<int>& res){
	int lens = weights.size();
	while(1){
		int idx = -1, min_val = INT_MAX;
		//每一次找到当前结果数组中的最小值
		for(int i=0;i<lens;i++){
			if(is_visited[i])	continue;
			if(res[i] < min_val){
				min_val = res[i];
				idx = i;
			}
		}
		is_visited[idx] = true;
		if(idx == lens-1)	return;
		//从当前的最小值出发
		//更新res数组中有连通性的节点的值（两者中取最小规则），方便下一个循环找到最小值
		for(int i=0;i<lens;i++){
			if(is_visited[i])	continue;
			if(marks[idx][i] == 1)	res[i] = min(res[i], res[idx]+weights[i]);
		}
	}
}

//使用dijkstra算法来解这道题
//与传统不同，这里计算的是节点的权值，而不是路径的权值
int main(){
	int N = 0, M = 0;
	while(cin >> N >> M){
		vector<int> weights(N, 0);
		//统计节点权值
		for(int i=0;i<N;i++)	cin >> weights[i];
		vector<vector<int>> marks(N, vector<int>(N, 0));
		//用二维数组来记录节点连通性
		//N比较大时耗时耗空间
		for(int i=0;i<M;i++){
			int a = 0, b = 0;
			cin >> a >> b;
			marks[a-1][b-1] = 1; marks[b-1][a-1] = 1;
		}
		//记录最终0点到任一点的结果数组
		vector<int> res(N, INT_MAX); res[0] = weights[0];
		//记录该节点是否被访问过
		vector<bool> is_visited(N, false);
		dijkstraSolver(weights, marks, is_visited, res);
		cout << res[N-1] << endl;
	}
	return 0;
}