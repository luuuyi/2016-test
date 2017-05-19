#include <bits/stdc++.h>

using namespace std;

int main(){
	int W = 0, N = 0;
	double x=0,Y = 0;
	while(cin >> W >> Y >> x >> N){
		for(int i=0;i<N;i++){
			Y = (Y+1)*(1-x) + 21*x;
		}
		cout << ceil(Y) << endl;
	}
	return 0;
}

#include <iostream>
#include <cmath>
 
using namespace std;
void AverageAge()
{
    // 总人数为W，平均年龄为Y岁
    // 每年离职率为x，x>0&&x<1
    double W, Y, x, N;
 
    while(cin >> W >> Y >> x >> N)
    {
        while(N--)
        {
            Y = 21 * x + (1 - x) * (Y + 1);
        }
 
        cout << ceil(Y) << endl;
    }
}
 
int main()
{
    AverageAge();
    return 0;
}