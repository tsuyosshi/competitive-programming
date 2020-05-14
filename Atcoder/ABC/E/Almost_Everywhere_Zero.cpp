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

string s;
int K;

int mem[110][110][3];

int calc(int n,int num,int isunder){
    if(mem[n][num][isunder]!=-1)return mem[n][num][isunder];
    if(n==s.size()){
        if(isunder==0)return 0;
        else {
            if(num==K)return 1;
            else return 0;
        }
    }
    int res=0;
    if(num==K)res++;
    for(int i=0;i<=9;++i){
        if(i==0&&n==0)continue;
        else{
            int _isunder;
            if(isunder==1)_isunder=1;
            else if(isunder==2&&s[n]-'0'==i)_isunder=2;
            else if(isunder==2&&s[n]-'0'>i)_isunder=1;
            else _isunder=0;
            if(i==0)res+=calc(n+1,num,_isunder);
            else res+=calc(n+1,num+1,_isunder);
        }
    }
    return mem[n][num][isunder]=res;
}

int main(){
    for(int i=0;i<110;++i)for(int j=0;j<110;++j)for(int k=0;k<3;++k)mem[i][j][k]=-1;
    cin>>s;
    cin>>K;
    cout<<calc(0,0,2)<<endl;
}