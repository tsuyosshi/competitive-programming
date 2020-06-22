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
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

ll p_num[1000005];
ll N;

ll ans=0;

vector<PL> p;

ll Pow(ll x,ll n){
    ll res=1;
    for(int i=0;i<n;++i)res*=x;
    return res;
}

int main(){
    cin>>N;
    ll x=N;
    for(ll j=2;j*j<=x;j++){
        ll k=0;
        while(x%j==0){
            k++;
            x/=j;
        }
        if(k!=0)p.push_back(PI(j,k));
    }
    if(x!=1)p.push_back(PI(x,1));
    for(int i=0;i<p.size();++i){
        ll n=(-1+sqrt(1+8*p[i].second))/2;
        ans+=n;
    }
    cout<<ans<<endl;

}