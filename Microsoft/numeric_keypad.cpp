//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

//初始化一个table用来保存状态
map<char, set<char>> init(){
    return map<char, set<char>>({
                                        {'1', {'0','1','2','3','4','5','6','7','8','9'}},
                                        {'2', {'0','2','3','5','6','8','9'}},
                                        {'3', {'3','6','9'}},
                                        {'4', {'0','4','5','6','7','8','9'}},
                                        {'5', {'0','5','6','8','9'}},
                                        {'6', {'6','9'}},
                                        {'7', {'0','7','8','9'}},
                                        {'8', {'0','8','9'}},
                                        {'9', {'9'}},
                                        {'0', {'0'}}
                                });
}

bool dfs(const string& s, int cur, int end, string &res, map<char, set<char>>& table){
    if(cur >= end)	return true;
    char tmp = res.back();
    //每一次在set里面找到大于给定符号的位置
	//这里很奇怪，将正向迭代器转为反向迭代器以后，反向迭代器为正向迭代器的位置-1
	//猜测是因为反向之后还要为rend留出一个反向迭代器的位置
    auto t = table[tmp].upper_bound(s[cur]);
	//如果发现所有的字符都大于当前字符，则代表错误情况发生了
    if(t == table[tmp].begin())	return false;
    //t--;
    //cout << *t << endl;
    //正向反向迭代器转换
    set<char>::reverse_iterator k(t);
    for(;k!=table[tmp].rend();k++){
        //如果相等的话继续dfs
        if(*k == s[cur]){
            res.push_back(*k);
			//dfs如果只需要一次正确答案的话，可以参照如下形式编码
            if(dfs(s, cur+1, end, res, table))	return true;
            res.pop_back();
        }
		//如果出现小于的情况，可以就用最大的符号来填充剩下的位置
        else if(*k < s[cur]){
            res.push_back(*k);
            char tail = (*k=='0'?'0':'9');
            string tail_s(end-cur-1, tail);
            res += tail_s;
            return true;
        }
    }
    return false;
}

int main(){
    int k = 0;
    map<char, set<char>> table = init();
    while(cin >> k) {
        while(k--) {
            string s;
            cin >> s;
            int lens = s.size();
            string res;
			//要注意的是，结果的第一位并不是很简单的等于测试用例的第一位
			//从约束条件来说，为第一位总是能取得最大值，但是考虑用例98
			//如果固定第一位的话，最终结果是9，显然错误
            res.push_back('1');
            dfs(s, 0, lens, res, table);
            cout << res.substr(1) << endl;
        }
        //cout << endl;
    }
    return 0;
}