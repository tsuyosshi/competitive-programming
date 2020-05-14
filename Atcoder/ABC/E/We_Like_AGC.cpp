#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long int ll;

const ll mod=1e9+7;

int N;
char c[5]={' ','A','G','C','T'};

ll mem[110][5][5][5];

bool check(string s){
    if(s.find("AGC")!=string::npos)return false;
    for(int j=0;j<s.size();++j){
        string t=s;
        swap(t[j],t[j+1]);
        if(t.find("AGC")!=string::npos)return false;
    }
    return true;
}

//A=1,G=2,C=3,T=4;
ll calc(int n,int pc,int ppc,int pppc){
    if(mem[n][pc][ppc][pppc]!=-1)return mem[n][pc][ppc][pppc];
    if(n==N)return 1;
    ll res=0;
    string s="";
    if(pppc!=0)s+=c[pppc];
    if(ppc!=0)s+=c[ppc];
    if(pc!=0)s+=c[pc];
    for(int i=1;i<=4;++i){
        string t=s+c[i];
        if(check(t))res+=calc(n+1,i,pc,ppc)%mod;
    }
    return mem[n][pc][ppc][pppc]=res%mod;
}

int main(){
    for(int i=0;i<110;++i)for(int j=0;j<5;++j)for(int k=0;k<5;++k)for(int l=0;l<5;++l)mem[i][j][k][l]=-1;
    cin>>N;
    cout<<calc(0,0,0,0)<<endl;
}