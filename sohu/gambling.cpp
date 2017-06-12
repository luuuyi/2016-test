#include <bits/stdc++.h>

using namespace std;

//检查子函数
bool check(string& s1, map<int, int>& m1){
	int count = 3;
	//检查
	for(int i=0;i<s1.size();){
		if(s1[i] == '1'){
			if(s1.substr(i, 2) == "10"){
				m1[10]++;
				i += 2;
				count--;
			}
			else	return false;
		}
		else{
			if((s1[i]>='2'&&s1[i]<='9')||s1[i]=='J'||s1[i]=='Q'||s1[i]=='K'||s1[i]=='A'){
				if(s1[i]>='2'&&s1[i]<='9')	m1[s1[i]-'0']++;
				else if(s1[i]=='J')	m1[11]++;
				else if(s1[i]=='Q')	m1[12]++;
				else if(s1[i]=='K')	m1[13]++;
				else	m1[14]++;
				i++;
				count--;
			}
			else	return false;
		}
	}
	//
	if(count == 0)	return true;
	else	return false;
}

vector<int> decode(map<int, int>& m){
	int lens = m.size();
	vector<int> ret;
	if(lens==1){
		//金花牌型，不必比较最大位
		ret.push_back(1); ret.push_back(m.begin()->first);
	}
	else if(lens==2){
		//对子牌型，需要记录对子大小和单张大小
		ret.push_back(3);
		//map的iterator貌似只支持++，=操作符重载
		map<int, int>::iterator it = m.begin();
		map<int, int>::iterator it1 = ++it;
		it = m.begin();
		if(it->second == 2){ret.push_back(it->first); ret.push_back(it1->first);}
		else{ret.push_back(it1->first); ret.push_back(it->first);}
	}
	else{
		map<int, int>::iterator it = m.begin();
		map<int, int>::iterator it1 = ++it;
		map<int, int>::iterator it2 = ++it;
		it = m.begin();
		//判断是普通牌型还是顺子牌型，并记录比较依据
		if(it2->first - it->first == 2){vector<int> tmp({2, it2->first}); ret.assign(tmp.begin(), tmp.end());}
		else{vector<int> tmp({4, it2->first, it1->first, it->first}); ret.assign(tmp.begin(), tmp.end());}
	}
	return ret;
}

//判断函数
int judge(map<int, int>& m1, map<int, int>& m2){
	//将输入的map解码成扎金花里面的规则结构
	vector<int> j1 = decode(m1), j2 = decode(m2);
	//第一位表示是什么牌型，之后第一位代表最大比较值，第二位代表次大比较值，以此类推
	if(j1[0] < j2[0])	return 1;
	else if(j1[0] > j2[0])	return -1;
	else{
		int lens = j1.size();
		for(int i=1;i<lens;i++){
			if(j1[i]>j2[i])	return 1;
			else if(j1[i]<j2[i])	return -1;
		}
		return 0;
	}
}

//主程序
int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		map<int, int> m1, m2;
		//首先检查输入是否规范，同时将输入解析到map中
		bool is_valid = check(s1, m1) && check(s2, m2);
		if(!is_valid)	return -2;
		//开始判断大小
		cout << judge(m1, m2) << endl;
	}
	return 0;
}