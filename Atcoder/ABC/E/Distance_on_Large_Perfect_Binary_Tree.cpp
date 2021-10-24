#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int mod=998244353;

int modPow(int a, int n) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

int N,D;
int ans;

signed main(){
    cin>>N>>D;
    if(D==1){
        for(int i=1;i<N;++i)ans=(ans+modPow(2,i))%mod;
        cout<<(2*ans)%mod<<endl;
        return 0;
    }
    for(int d=1;d<=N;++d){
        int cnt=0;
        int l=max(D+d-N,1ll),r=min(N-d,D-1);
        if(d+D<=N){
            cnt+=2*modPow(2,D);
            cnt%=mod;
        }
        if(l<=r&&D>1){
            cnt+=2*(r-l+1)*modPow(2,D-2);
            cnt%=mod;
            cnt*=modPow(2,d-1);
            cnt%=mod;
        }
        ans=(ans+cnt)%mod;
    }
    cout<<ans<<endl;
}