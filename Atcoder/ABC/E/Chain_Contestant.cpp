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
string S;
const int J=10;

int dp[1005][2005][15];
int ans;

signed main(){
    cin>>N;
    cin>>S;
    dp[0][0][0]=1;
    dp[0][(1<<(S[0]-'A'))][S[0]-'A'+1]=1;
    for(int i=0;i<N-1;++i){
        int c=S[i+1]-'A';
        for(int j=0;j<(1<<J);++j){
            for(int k=0;k<=J;++k){
                int b=(1<<c);
                // 続けて同じコンテスト
                if(k==c+1){
                    dp[i+1][j][k]+=dp[i][j][k]; // コンテストにでる
                    dp[i+1][j][k]%=mod;
                    dp[i+1][j][k]+=dp[i][j][k]; // コンテストにでない
                    dp[i+1][j][k]%=mod;
                }
                // 異なるコンテスト
                else {
                    if(!(j&b)){
                        dp[i+1][j+b][c+1]+=dp[i][j][k]; // コンテストにでる
                        dp[i+1][j+b][c+1]%=mod;
                    }
                    dp[i+1][j][k]+=dp[i][j][k]; // コンテストにでない
                    dp[i+1][j][k]%=mod;
                }
            }
        }
    }
    for(int j=1;j<(1<<J);++j)for(int k=0;k<=10;++k){
        ans+=dp[N-1][j][k];
        ans%=mod;
    }
    cout<<ans<<endl;
}