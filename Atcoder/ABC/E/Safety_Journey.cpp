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
int N,M,K;
bool broken[5005][5005];
vector<int> C[5005];
int dp[5005][5005];

signed main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        broken[u][v]=true;
    }
    for(int u=0;u<N-1;++u)for(int v=u+1;v<N;++v)if(broken[u][v]){
        C[u].push_back(v);
        C[v].push_back(u);
    }
    dp[0][0]=1;
    for(int k=0;k<K;++k){
        int A=0;
        for(int n=0;n<N;++n)A+=dp[k][n];
        for(int u=0;u<N;++u){
            dp[k+1][u]=A-dp[k][u];
            dp[k+1][u]=(dp[k+1][u]+mod)%mod;
            for(auto n:C[u]){
                dp[k+1][u]-=dp[k][n];
                dp[k+1][u]=(dp[k+1][u]+mod)%mod;
            }
        }
    }
    cout<<dp[K][0]<<endl;
}