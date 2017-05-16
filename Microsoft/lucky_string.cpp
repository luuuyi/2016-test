#include <bits/stdc++.h>

using namespace std;

set<int> table({1,2,3,5,8});

bool isLucky(string s){
    int lens = s.size();
    set<char> tmp;
    for(int i=0;i<lens;i++){
        tmp.insert(s[i]);
    }
    int tab = tmp.size();
    if(table.find(tab)!=table.end())    return true;
    else    return false;
}

void print(set<string>& ret){
    for(auto k = ret.begin();k!=ret.end();k++){
        cout << *k << endl;
    }
}

int main(){
    string str;
    cin >> str;
    int lens = str.size();
    set<string> ret;
    for(int k=1;k<=lens;k++){
        for(int i=0;i<=lens-k;i++){
            string tmp = str.substr(i,k);
            if(isLucky(tmp))    ret.insert(tmp);
        }
    }
    print(ret);
    return 0;
}