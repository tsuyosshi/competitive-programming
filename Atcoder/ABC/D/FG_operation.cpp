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
int A[100005];
int dp[100005][10][10];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    dp[0][A[0]][A[1]]=1;
    for(int i=0;i<N-1;++i){
        for(int j=0;j<10;++j){
            for(int k=0;k<10;++k){
                if(i!=N-2){
                    dp[i+1][(j+k)%10][A[i+2]]+=dp[i][j][k];
                    dp[i+1][(j*k)%10][A[i+2]]+=dp[i][j][k];
                    dp[i+1][(j+k)%10][A[i+2]]%=mod;
                    dp[i+1][(j*k)%10][A[i+2]]%=mod;
                }
                else {
                    dp[i+1][(j+k)%10][0]+=dp[i][j][k];
                    dp[i+1][(j*k)%10][0]+=dp[i][j][k];
                    dp[i+1][(j+k)%10][0]%=mod;
                    dp[i+1][(j*k)%10][0]%=mod;
                }
            }
        }
    }
    for(int i=0;i<10;++i){
        cout<<dp[N-1][i][0]<<endl;
    }
}