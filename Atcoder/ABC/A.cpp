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
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

ll N;
ll A[200005],B[200005];

double div[200005];
map<double,ll> m;

ll ans;


ll modPow(ll a, ll n) {
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    ll t=modPow(a,n/2);
    return (t*t)%mod;
}

ll modDiv(ll a,ll b){
    return (a%mod*modPow(b,mod-2))%mod;
}

int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A[i]>>B[i];
        //div[i]=1;//(double)A[i]/B[i];
        //map[div[i]]++;
    }
    ans=((N%mod)*(N-1)%mod)%mod;
    for(int i=0;i<N;++i){
        //ans-=(map[div[i]-1]);
        ans=(ans+mod)%mod;
    }
    cout<<modDiv(ans,2)<<endl;
}