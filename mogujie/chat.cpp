#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

//基于任意一个起床时间，查找a的时间段和b的时间段是否有时刻重合
bool isValid(const vector<vector<int>>& a_times, const vector<vector<int>>& b_times, int t){
    int a_lens = a_times.size(), b_lens = b_times.size();
    for(int i=0;i<a_lens;i++){
        for(int j=0;j<b_lens;j++){
            if(!(b_times[j][0]+t>a_times[i][1] || b_times[j][1]+t<a_times[i][0]))   return true;
        }
    }
    return false;
}

//解题思路：
//暴力解法，只要判断a的空闲时间段和b的空闲时间段有某一个时刻重叠
//即判断为可行的时间段之一
//枚举每一个可行的起床时间
int getResult(const vector<vector<int>>& a_times, const vector<vector<int>>& b_times, int l, int r){
    int count = 0;
    for(int i=l;i<=r;i++){
        if(isValid(a_times, b_times, i))    ++count;
    }
    return count;
}

int main(){
    int p = 0, q = 0, l = 0, r = 0;
    while(cin >> p >> q >> l >> r){
        vector<vector<int>> a_times(p, vector<int>(2, 0));
        vector<vector<int>> b_times(q, vector<int>(2, 0));
        for(int i=0;i<p;i++)    cin >> a_times[i][0] >> a_times[i][1];
        for(int i=0;i<q;i++)    cin >> b_times[i][0] >> b_times[i][1];
        cout << getResult(a_times, b_times, l, r) << endl;
    }
    return 0;
}