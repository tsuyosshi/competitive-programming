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

const int MAX_N=80;
const int MAX_C=25000000;

int N;
int A[MAX_N+1];
int dp[MAX_N+1];
int ans;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    dp[0]=1000;
    for(int i=0;i<N;++i){
        chmax(dp[i+1],dp[i]);
        for(int j=0;j<=i;++j){
            int pl=(dp[j]/A[j])*A[i];
            int mn=(dp[j]/A[j])*A[j];
            chmax(dp[i+1],dp[j]-mn+pl);
        }
    }
    for(int i=0;i<=N;++i)chmax(ans,dp[i]);
    cout<<ans<<endl;
}