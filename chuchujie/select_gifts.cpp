#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

double getResult(vector<vector<double>>& persons, vector<int>& gifts, int N, int M){
	
}

int main(){
	int N = 0, M = 0;
	while(cin >> N >> M){
		vector<vector<double>> persons(N, vector<double>(M, 0));
		vector<int> gifts(M, 0);
		for(int i=0;i<M;i++)	cin >> gifts[i];
		for(int i=0;i<N;i++)	for(int j=0;j<M;j++)	cin >> persons[i][j];
		cout << getResult(persons, gifts, N, M) << endl;
	}
	return 0;
}