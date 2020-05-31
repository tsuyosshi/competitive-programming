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
#include<limits.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
typedef pair<ll,ll> PL;
typedef pair<ll,pair<ll,ll>> PLL;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const double eps=1e-13;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

ll N,K;

ll modPow(ll a, ll n) {
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    ll t=modPow(a,n/2);
    return (t*t)%mod;
}

int main(){
    cin>>N>>K;
    ll ans=0;
    for(ll g=K;g>=1;--g){
        ll c=K/g;
        ans+=modPow(c,N);
        ans%=mod;
    }
    cout<<ans<<endl;
}