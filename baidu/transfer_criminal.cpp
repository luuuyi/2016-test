//先用一个数组来统计所有罪犯的顺序累加罪行，最后用i和i+c处的值相减，判断是否满足条件即可，总共三个for循环，耗时10ms
#include <bits/stdc++.h>

using namespace std;

int getResult(vector<int>& crims, int n, int t, int c){
    int count = 0;
    vector<long long> sums(n+1, 0);
    sums[0] = 0;
    long long sum = 0;
    //累加罪行
    for(int i=0;i<n;i++){
        sum += crims[i];
        sums[i+1] = sum;
    }
    //判断区间累加罪行是否满足条件
    for(int i=0;i<n+1-c;i++){
        if(sums[i+c] - sums[i] <= t)    ++count;
    }
    return count;
}

int main(){
    int n = 0, t = 0, c = 0;
    while(cin >> n >> t >> c){
        vector<int> crims(n,0);
        for(int i=0;i<n;i++)    cin >> crims[i];
        cout << getResult(crims, n, t, c) << endl;
    }
    return 0;
}

//另一个更优化的解法，在读取每个罪犯罪行值得时候先统计前c个罪犯的罪行（累计罪行）
//之后每一次对累计罪行减一个最前端的罪行，再加一个最后端的罪行，直到最后一个罪行值被读取
#include<stdio.h>
int main(){
    int n,t,c;
    while(scanf("%d %d %d",&n,&t,&c)!=EOF){
        int i,j,x=0,sum=0,a[200000];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(i<c)
                sum += a[i];
        }
        if(sum <= t){
            x++;
        }
        for(i=1;i<=n-c;i++){
            sum = sum + a[c+i-1];
            sum = sum - a[i-1];
            if(sum<=t){
                x++;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}