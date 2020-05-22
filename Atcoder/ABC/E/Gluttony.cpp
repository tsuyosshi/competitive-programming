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

int N;
ll K;
ll A[200005],F[200005];

bool ok(ll m){
    ll cost=0;
    for(int i=0; i<N; i++){
        if(F[i]*A[i]<=m)continue;
        cost+=A[i]-m/F[i];
    }
    return (cost<=K);
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i)cin>>F[i];
    sort(A,A+N);
    sort(F,F+N,greater<int>());
    ll l=0,r=1e18;
    ll mid;
    int T=100;
    while(T--){
        mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid;
    }
    if(ok(l))cout<<l<<endl;
    else cout<<r<<endl;
}