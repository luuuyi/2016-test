//#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//比较函数，在统计量相同的情况下，先出现的错误记录排在前面
bool cmp(pair<string, vector<int> > a, pair<string, vector<int> > b){
    if(a.second.at(0) == b.second.at(0))  return a.second.at(1) < b.second.at(1);
    return a.second.at(0) > b.second.at(0);
}

void help(const unordered_map<string, vector<int> >& table){
    vector<pair<string, vector<int> > > dump_vec;
    //将table里面的值放入vector里面，方便之后的按规则利用value排序
    for(auto k=table.begin();k!=table.end();k++)    dump_vec.push_back(make_pair(k->first, k->second));
    stable_sort(dump_vec.begin(), dump_vec.end(), cmp);
    //取前8个记录，同时对于文件名超过16位的记录，只需输出最后16位
    for(int i=0;i<8;i++){
        string title = dump_vec[i].first;
        int pos = title.find(' ');
        if(pos <= 16)   cout << title << " " << dump_vec[i].second.at(0) << endl;
        else{
            string output = title.substr(pos-16);
            cout << output << " " << dump_vec[i].second.at(0) << endl;
        }
    }
}

int main(){
    string s;
    unordered_map<string, vector<int> > table;
    int i = 0;
    while(getline(cin, s)){
        int pos = s.find_last_of('\\');
        string tmp = s.substr(pos+1);
        if(table.find(tmp) == table.end()){
            table[tmp].push_back(1);
            table[tmp].push_back(i);
        }
        else    table[tmp][0]++;
        i++;
    }
    help(table);
    return 0;
}