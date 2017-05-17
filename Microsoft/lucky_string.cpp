#include <bits/stdc++.h>

using namespace std;

set<int> table({ 1, 2, 3, 5, 8,13,21,34,55,89 });

void print(set<string>& ret){
	for (auto k = ret.begin(); k != ret.end(); k++){
		//cout << k->first << endl;
		cout << *k << endl;
	}
}

int main(){
	string str;
	cin >> str;
	int lens = str.size();
	set<string> ret;
	for (int i = 0; i<lens; i++){
		set<char> mp;
		for (int j = i; j<lens; j++){
			mp.insert(str[j]);
			if (table.find(mp.size()) != table.end())  ret.insert(str.substr(i, j - i + 1));//++ret[str.substr(i, j - i + 1)];
		}
	}
	print(ret);
	return 0;
}