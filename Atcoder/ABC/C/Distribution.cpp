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

int N;
int S[200005],T[200005];
int dp[200005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>S[i];
    int s,mi=INF;
    for(int i=0;i<N;++i){
        cin>>T[i];
        if(mi>T[i]){
            mi=T[i];
            s=i;
        }
    }
    dp[s]=mi;
    for(int i=1;i<N;++i)dp[(s+i)%N]=min(dp[(s+i-1)%N]+S[(s+i-1)%N],T[(s+i)%N]);
    for(int i=0;i<N;++i)cout<<dp[i]<<endl;
}