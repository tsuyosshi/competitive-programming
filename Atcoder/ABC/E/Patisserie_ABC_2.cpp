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

int N,K;
int dp[4][3000005];

signed main(){
    cin>>N>>K;
    for(int i=1;i<=N;++i)dp[1][i]=1;
    for(int i=2;i<=3;++i){
        vector<int> v(3000005,0);
        for(int j=1;j<=i*N;++j)v[j]=v[j-1]+dp[i-1][j];
        for(int j=1;j<=i*N;++j){
            dp[i][j]+=v[j-1]-v[max(0ll,j-N-1)];
        }
    }
    int X=0;
    for(int i=1;i<=3*N;++i){
        if(K-dp[3][i]<=0){
            X=i;
            break;
        }
        K-=dp[3][i];
    }
    int C=min(X-2,N);
    for(int i=1;i<=N;++i){
        int l=max(1ll,X-i-C);
        int r=min(C,X-i-1);
        if(l>r)continue;
        if(K-(r-l+1)<=0){
            for(int j=1;j<=N;++j){
                int k=X-(i+j);
                if(k>=1&&k<=N){
                    K--;
                    if(K==0){
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        return 0;
                    }
                }
            }
            break;
        }
        else K-=r-l+1;
    }
}