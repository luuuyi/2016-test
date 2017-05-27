#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//解答函数
void judge(vector<vector<double>>& probs, int n, int m, int x, int y, int t){
    double cc = probs[x-1][y-1];
    //ss每分钟随机选择一个方格钓鱼
    //即可认为ss钓到鱼的概率为所有方格概率相加的平均值
    double ss = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)    ss += probs[i][j];
    }
    ss /= n*m;
    //题目需要求t分钟后至少钓到一条鱼的概率
    //可以理解成一条鱼都没钓到的补集，所以可以对每一分钟钓不到鱼的概率求一个t次方得到结果
    //最后求解补集即可
    cc = 1 - pow(1-cc, t);
    ss = 1 - pow(1-ss, t);
    if(cc==ss){
        cout << "equel" << endl;
        cout << fixed << setprecision(2) << cc << endl;
    }
    else if(cc>ss){
        cout << "cc" << endl;
        cout << fixed << setprecision(2) << cc << endl;
    }
    else{
        cout << "ss" << endl;
        cout << fixed << setprecision(2) << ss << endl;
    }
}

int main(){
    int n = 0, m = 0, x = 0, y = 0, t = 0;
    while(cin >> n >> m >> x >> y >> t){
        vector<vector<double>> probs(n, vector<double>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> probs[i][j];
            }
        }
        judge(probs, n, m, x, y, t);
    }
    return 0;
}