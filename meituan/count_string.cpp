#include <bits/stdc++.h>

using namespace std;

long long calcu(string& str1,string& str2, int lens){
	long long ret = 0;
	int base = 1, lens1 = str1.size(), lens2 = str2.size();
	for(int i=lens-1;i>=0;i--){
		ret += ((i>=lens2?'a'-1:str2[i]) - (i>=lens1?'a'-1:str1[i])) * base;
		base *= 26;
	}
	return ret;
}

int main(){
	int lens1 = 0, lens2 = 0;
	string str1, str2;
	while(cin >> str1 >> str2 >> lens1 >> lens2){
		long long ret = 0;
		for(int i=lens1;i<=lens2;i++){
			ret += calcu(str1, str2, i);
		}
		ret = (ret-1) % 1000007;
		cout << ret << endl;
	}
	return 0;
}

测试用例:
cpqejrrgp cpqejtrdg 9 9

对应输出应该为:

35064