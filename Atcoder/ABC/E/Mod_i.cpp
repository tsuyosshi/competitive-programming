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

const int mod=1e9+7;
int N;
int A[3005];
int V[3005];
int dp[3005][3005]; //dp[n][k]: n番目まででk個に切り分ける通り数
int c[3005][3005]; //c[i][j][m]: V[k]%j=mとなるdp[k][j]の和 (k<i)
//dp[i][j] += c[i][j-1][V[i]%j]
//c[i+1][j-1][V[i]%j] += dp[i][j-1] 

signed main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>A[i];
        V[i]+=V[i-1]+A[i];
    }
    for(int i=1;i<=N;++i){
        dp[i][1]=1;
    }
    c[1][V[1]%2]=dp[1][1];
    for(int i=2;i<=N;++i){
        for(int j=2;j<=i+1;++j){
            if(j<=i){
                dp[i][j]+=c[j-1][V[i]%j];
                dp[i][j]%=mod;
            }
            c[j-1][V[i]%j]+=dp[i][j-1];
            c[j-1][V[i]%j]%=mod;
        }
    }
    int ans=0;
    for(int i=1;i<=N;++i){
        ans+=dp[N][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}