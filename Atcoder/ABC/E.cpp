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

double Div[200005];
double Div_inv[200005];
map<double,ll> m;
map<double,ll> m_i;

double K[200005];

ll ans=0;

ll fact[200010];
ll fact_inv[200010];


class Comb{
public:
    Comb(ll N){
        fact[0]=1;
        fact_inv[0]=1;
        for(int i=1;i<=N;++i){
            fact[i]=fact[i-1]*i%mod;
            fact_inv[i]=modPow(fact[i],mod-2);
        }
    }

    ll modPow(ll a, ll n) {
        if(n==1)return a%mod;
        if (n%2==1)return(a*modPow(a,n-1))%mod;
        ll t=modPow(a,n/2);
        return (t*t)%mod;
    }

    ll comb(ll n,ll r){
        return (((fact[n]*fact_inv[r])%mod)*fact_inv[n-r])%mod;
    }
};

int main(){
    cin>>N;
    Comb C(N+5);
    for(int i=0;i<N;++i){
        cin>>A[i]>>B[i];
        Div[i]=(double)A[i]/B[i];
        Div_inv[i]=(double)1.0/Div[i];
        m[Div[i]]++;
        cout<<Div_inv[i]<<endl;
        m_i[Div_inv[i]]++;
    }
    ans+=C.comb(N+1,1)-1;
    for (auto itr=m.begin();itr!=m.end();++itr){
        int d=itr->second;
        double a=itr->first;
        //cout<<a<<endl;
        double b=-(double)1.0/a;
        int di=m_i[b];
        //cout<<b<<endl;
        if(di<=0)continue;
        //cout<<di<<endl;
        ans-=(C.comb(di,2)-C.comb(N-2+1,1))*C.modPow(2,mod-2);
        ans=(ans+mod)%mod;
    }
    cout<<ans<<endl;
}