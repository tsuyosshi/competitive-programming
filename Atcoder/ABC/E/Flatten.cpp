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

ll p_num[1000005];

ll modPow(ll a, ll n) {
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    ll t=modPow(a,n/2);
    return (t*t)%mod;
}

ll modDiv(ll a,ll b){
    return (a%mod)*modPow(b,mod-2)%mod;
}



ll N;
ll A[10004];

int main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    ll ans=0;
    for(int i=0;i<N;++i){
        ll x=A[i];
        for(ll j=2;j*j<=x;j++){
            ll k=0;
            while(x%j==0){
                k++;
                x/=j;
            }
            p_num[j]=max(k,p_num[j]);
        }
        if(x!=1)p_num[x]=max(1LL,p_num[x]);
    }
    ll X=1;
    for(int i=0;i<1000001;++i){
        for(int j=0;j<p_num[i];++j){
            X*=i;
            X%=mod;
        }
    }
    for(int i=0;i<N;++i){
        ans+=modDiv(X,A[i]);
        ans%=mod;
    }
    cout<<ans<<endl;
}