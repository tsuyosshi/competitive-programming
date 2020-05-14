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

string N;
ll ans;

ll calc(int n,int isupper,int f,int l){
    if(n==N.size()-1){
        if(isupper==1)return 0;
        if(isupper==2&&N[N.size()-1]-'0'<l)return 0;
        else return 1;
    }
    ll res=0;
    for(int i=0;i<=9;++i){
        if(n==0)if(i!=f)continue;
        int _isupper;
        if(isupper==0)_isupper=0;
        else if(isupper==2&&i==N[n]-'0')_isupper=2;
        else if(isupper==2&&i<N[n]-'0')_isupper=0;
        else _isupper=1;
        if(i==l)res+=calc(n+1,_isupper,f,l)+1;
        else res+=calc(n+1,_isupper,f,l);
    }
    return res;
}

int main(){
    cin>>N;
    for(int a1=1;a1<=9;++a1){
        for(int a2=1;a2<=9;++a2){
            ans+=calc(0,2,a1,a2)*calc(0,2,a2,a1);
        }
    }
    cout<<ans<<endl;
}