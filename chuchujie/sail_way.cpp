#include <bits/stdc++.h>

using namespace std;

void dijkstraSolver(vector<vector<vector<int>>>& sail_map, vector<int>& cost, vector<bool>& is_vist, int n){
	//dijkstra算法，每一次选择最短的状态作为中间态，然后再去更新所有的状态
	//可以计算出到初始点到每一个点（包括自己）的最短距离
	int unvisit = n;
	while(unvisit--){
		//先找到当前状态中最优中间态
		int idx = -1, min_val = 0x7fffffff;
		for(int i=0;i<n;i++){
			if(is_vist[i])	continue;
			if(cost[i] < min_val){
				idx = i; min_val = cost[i];
			}
		}
		is_vist[idx] = true;
		//根据最优中间态再去更新剩余的点的状态
		for(int i=0;i<n;i++){
			if(is_vist[i])	continue;
			//首先保证两点之间可达
			if(sail_map[idx][i][0]<INT_MAX){
				//其次判断航行时间区间和禁航时间区间是否重叠，然后再来更新到每一个点的时间是多少
				if(!(cost[idx]+sail_map[idx][i][0]<sail_map[idx][i][1] || cost[idx]>sail_map[idx][i][2])){
					cost[i] = min(cost[i], sail_map[idx][i][2]+sail_map[idx][i][0]);
				}
				else	cost[i] = min(cost[i], cost[idx]+sail_map[idx][i][0]);
			}
		}
	}
}

//
int main(){
	int n = 0, m = 0;
	while(cin >> n >> m){
		vector<vector<vector<int>>> sail_map(n, vector<vector<int>>(n, vector<int>(3, INT_MAX)));
		int start = 0, end = 0, dist = 0, l = 0, r = 0;
		for(int i=0;i<m;i++){
			cin >> start >> end >> dist >> l >> r;
			sail_map[start-1][end-1][0] = dist; sail_map[start-1][end-1][1] = l; sail_map[start-1][end-1][2] = r;
			sail_map[end-1][start-1][0] = dist; sail_map[end-1][start-1][1] = l; sail_map[end-1][start-1][2] = r;
		}
		//先更新初始状态，主要是更新cost列表
		vector<int> cost(n, INT_MAX); cost[0] = 0;
		vector<bool> is_vist(n, false);
		dijkstraSolver(sail_map, cost, is_vist, n);
		//莫名的最后要给输出的时间+1，也行即时不是从0开始的
		cout << cost[n-1]+1 << endl;
	}
	return 0;
}