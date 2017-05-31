#include <bits/stdc++.h>

using namespace std;

//解题思路
//剑指offer原题，找到原来顺序排序的结果与乱序排序之后结果的映射
//最后得到一个递推公式
int getLastOne(int n, int m){
    int n1 = 0;
    for(int i=2;i<=n;i++){
        n1 = (n1 + m) % i;
    }
    return n1;
}

int main(){
    int n = 0;
    while(cin >> n){
        cout << getLastOne(n, 3) << endl;
    }
    return 0;
}