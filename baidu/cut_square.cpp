#include <bits/stdc++.h>

using namespace std;

//解答函数
int getResult(vector<vector<int>>& crims, int n){
    int x_min = 0, x_max = 0;
    int y_min = 0, y_max = 0;
    //统计所有点中x方向和y方向上的最大点和最小点
    for(int i=0;i<n;i++){
        x_min = min(x_min, crims[i][0]);
        x_max = max(x_max, crims[i][0]);
        y_min = min(y_min, crims[i][1]);
        y_max = max(y_max, crims[i][1]);
    }
    //以最大的那个边为基准来画一个正方形
    int side = max(x_max-x_min, y_max-y_min);
    return side*side;
}

int main(){
    int n = 0;
    while(cin >> n){
        vector<vector<int>> crims(n, vector<int>(2,0));
        for(int i=0;i<n;i++){
            cin >> crims[i][0] >> crims[i][1];
        }
        cout << getResult(crims, n) << endl;
    }
    return 0;
}