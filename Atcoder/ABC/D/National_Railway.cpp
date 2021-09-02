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

int H,W;
int C;
int A[1005][1005];
int mi[1005][1005];
int dp[1005][1005];

signed main(){
    cin>>H>>W;
    cin>>C;
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)cin>>A[y][x];
    int ans=INF;
    for(int y=0;y<=H;++y)for(int x=0;x<=W;++x){
        mi[y][x]=INF;
        dp[y][x]=INF;
    }
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)mi[y][x]=min(A[y][x]-C*(x+y),min(mi[y-1][x],mi[y][x-1]));
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)dp[y][x]=A[y][x]+C*(x+y)+min(mi[y-1][x],mi[y][x-1]);
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)chmin(ans,dp[y][x]);
    //反転
    for(int y=1;y<=H/2;++y)for(int x=1;x<=W;++x)swap(A[y][x],A[H-y+1][x]);
    for(int y=0;y<=H;++y)for(int x=0;x<=W;++x){
        mi[y][x]=INF;
        dp[y][x]=INF;
    }
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)mi[y][x]=min(A[y][x]-C*(x+y),min(mi[y-1][x],mi[y][x-1]));
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)dp[y][x]=A[y][x]+C*(x+y)+min(mi[y-1][x],mi[y][x-1]);
    for(int y=1;y<=H;++y)for(int x=1;x<=W;++x)chmin(ans,dp[y][x]);
    cout<<ans<<endl;
}