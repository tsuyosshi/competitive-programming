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
int N;
int A[3005],B[3005];
int dp[3005][3005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i)cin>>B[i];
    for(int i=A[0];i<=B[0];++i)dp[0][i]=1;
    for(int i=1;i<N;++i){
        int sum=0;
        for(int j=0;j<A[i];++j){
            sum+=dp[i-1][j];
            sum%=mod;
        }
        for(int j=A[i];j<=B[i];++j){
            sum+=dp[i-1][j];
            sum%=mod;
            dp[i][j]+=sum;
            dp[i][j]%=mod;
            /*for(int k=0;k<=j;++k){
                dp[i][j]+=dp[i-1][k];
            }*/
            //cout<<"i, j : "<<i<<" "<<j<<endl;
            //cout<<dp[i][j]<<endl;
        }
    }
    int ans=0;
    for(int i=A[N-1];i<=B[N-1];++i){
        ans+=dp[N-1][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}