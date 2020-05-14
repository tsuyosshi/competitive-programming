#include <bits/stdc++.h>

using namespace std;

int K;
queue<string> que;

int main(){
    cin>>K;
    for(int i=1;i<=9;++i){ 
        string tmp="";
        tmp.push_back('0'+i);
        que.push(tmp);
    }
    int cnt=0;
    string  lnum;
    while(cnt<K){
        lnum=que.front();
        que.pop();
        int dig=lnum[lnum.size()-1]-'0';
        for(int i=max(dig-1,0);i<=min(dig+1,9);++i){
            string lnum_n=lnum;
            lnum_n.push_back(i+'0');
            que.push(lnum_n);
        }
        cnt++;
    }
    cout<<lnum<<endl;
}