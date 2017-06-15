#include <bits/stdc++.h>

using namespace std;

void check(vector<set<int>>& total, int m){
	set<int> cheat;
	for(int i=0;i<m;i++){
		for(auto k=total[i].begin();k!=total[i].end();k++){
			//跳过自己回答自己的情况
			if(*k == i)	continue;
			//如果回答人中有作弊用户，则该用户也看做是作弊用户
			if(cheat.find(*k) != cheat.end()){
				cheat.insert(i);
				break;
			}
			//如果回答人的提问中，出现该用户，即双方都可以判作作弊用户
			if(total[*k].find(i) != total[*k].end()){
				cheat.insert(i);
				cheat.insert(*k);
			}
		}
	}
	int lens = cheat.size();
	cout << lens << endl;
	for(auto k=cheat.begin();k!=cheat.end();k++){
		cout << *k+1;
		//在set的打印环节，可以考虑引入长度作为打印规则的依据
		if(--lens)	cout << " ";
		else	cout << endl;
	}
}

int main(){
	int m = 0;
	while (cin >> m){
		vector<set<int>> total(m);
		int user = 0, nums  = 0, tmp = 0;
		for(int k=0;k<m;k++){
			//预先将所有ID都设置成ID-1的形式
			cin >> user >> nums;
			for(int i=0;i<nums;i++){
				cin >> tmp;
				total[user-1].insert(tmp-1);
			}
		}
		check(total, m);
	}
	return 0;
}