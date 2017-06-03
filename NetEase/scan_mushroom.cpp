#include <bits/stdc++.h>

using namespace std;

//扫描所有方格中的局部最优解，返回局部最优解的所有可能情况
vector<vector<int>> scan(vector<vector<int>>& mushrooms, int n, int m){
	int ix = -1, iy = -1, max_val = 0x80000000;
	vector<vector<int>> res;
	//暴力遍历每一个点
	for(int i=0;i<=n-3;i++){
		for(int j=0;j<=m-3;j++){
			//判断方格上是否有蘑菇可以扫描
			int tmp_val = 0;
			for(int p=0;p<3;p++){
				for(int q=0;q<3;q++){
					tmp_val += (mushrooms[i+p][j+q]>=1?1:0);
				}
			}
			if(tmp_val > max_val){
				res.clear(); max_val = tmp_val;
				res.push_back(vector<int>({i, j, tmp_val}));
			}
			else if(tmp_val == max_val)	res.push_back(vector<int>({i, j, tmp_val}));
		}
	}
	return res;
}

//第二次代入局部最优解以后再求能扫描到的最大数量蘑菇
//最终还需要把局部最优解去掉的蘑菇还原
int eraseAndScan(vector<vector<int>>& mushrooms, int n, int m, int x, int y){
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++)
			mushrooms[i][j]--;
	}
	vector<vector<int>> res = scan(mushrooms, n, m);
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++)
			mushrooms[i][j]++;
	}
	return res[0][2];
} 

int main(){
	int n = 0, m = 0, k = 0;
	while (cin >> n >> m >> k){
		vector<vector<int>> mushrooms(n, vector<int>(m, 0));
		for(int i=0;i<k;i++){
			int x = 0, y = 0;
			cin >> x >> y;
			mushrooms[x-1][y-1]++;
		}
		int total = 0;
		//第一次先扫描出所有的局部最优解
		vector<vector<int>> res1 = scan(mushrooms, n, m);
		//第二次用每一个局部最优解带入，寻找最终的最优解
		for(int i=0;i<res1.size();i++){
			int tmp = res1[i][2], x = res1[i][0], y = res1[i][1];
			tmp += eraseAndScan(mushrooms, n, m, x, y);
			total = max(total, tmp);
		}
		cout << total << endl;
	}
	return 0;
}