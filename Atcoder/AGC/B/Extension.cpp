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

int A,B,C,D;

int dp[3005][3005];

signed main(){
    cin>>A>>B>>C>>D;
    dp[0][0]=1;
    for(int y=0;y<=D-B;++y){
        for(int x=0;x<=C-A;++x){
            if(x>=1)dp[y][x]+=((y+B)*dp[y][x-1])%mod;
            if(y>=1)dp[y][x]+=((x+A)*dp[y-1][x])%mod;
            if(x>=1&&y>=1)dp[y][x]=(dp[y][x]-(x+A-1)*(y+B-1)*dp[y-1][x-1]+mod)%mod;
            dp[y][x]=(dp[y][x]+mod)%mod;
        }
    }
    cout<<dp[D-B][C-A]<<endl;
}