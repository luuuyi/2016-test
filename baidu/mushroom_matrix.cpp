#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//解答函数
//错误思路：不碰到蘑菇的概率为：不碰到蘑菇的路径数 / 总路径数
//原因：总的来说每条路径的选择概率是不一样的；
/*如： 
  1 2 3 
  4 5 6 
  1->2 概率是0.5，2->3概率是0.5，3->6概率是1 
  1->2 概率是0.5，2->5概率是0.5，5->6概率是1 
  1->4 概率是0.5，4->5概率是   1，3->6概率是1 
  可以发现1-2-3-6与1-2-5-6的概率为0.25，而1-4-5-6概率为0.5 
  所以直接用可达路径数/总路径数求概率是不对的。*/
double getProb_v1(const vector<vector<bool>>& mushroom, int n, int m){
    vector<vector<int>> dp1(n, vector<int>(m, 1));
    vector<vector<int>> dp2(n, vector<int>(m, 0));
    for(int i=n-1;i>=0;i--){
        if(mushroom[i][m-1])    break;
        dp2[i][m-1] = 1;
    }
    for(int i=m-1;i>=0;i--){
        if(mushroom[n-1][i])    break;
        dp2[n-1][i] = 1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp1[i][j] = dp1[i+1][j] + dp1[i][j+1];
            if(mushroom[i][j])  dp2[i][j] = 0;
            else    dp2[i][j] = dp2[i+1][j] + dp2[i][j+1];
        }
    }
    return double(dp1[0][0]-dp2[0][0]) / dp1[0][0];
}

//正确思路：
//用dp的方法来解，每一个单元代表不喷到蘑菇走到该点的概率
double getProb_v2(const vector<vector<bool>>& mushroom, int n, int m){
    vector<vector<double>> dp(n, vector<double>(m, 0));
    dp[0][0] = 1.0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mushroom[i][j])  dp[i][j] = 0;
            else if(i==0 && j==0)    continue;
            //每一个点正常情况下等于上一个点和左边的点概率值的一半
            //考虑左边和上边的点在边界上，这样的话该点就为左边或上边的点的全部概率值
            else    dp[i][j] = (i==0?0:(j!=m-1?dp[i-1][j]*0.5:dp[i-1][j])) + (j==0?0:(i!=n-1?dp[i][j-1]*0.5:dp[i][j-1]));
        }
    }
    return dp[n-1][m-1];
}

int main(){
    int n = 0, m = 0, k = 0;
    while(cin >> n >> m >> k){
        vector<vector<bool>> mushroom(n, vector<bool>(m,false));
        int x = 0, y = 0;
        for(int i=0;i<k;i++){
            cin >> x >> y;
            mushroom[x-1][y-1] = true;
        }
        cout << fixed << setprecision(2) << getProb_v2(mushroom, n, m) << endl;
    }
    return 0;
}