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