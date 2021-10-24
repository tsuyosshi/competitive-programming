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

int N,M;vector<int> Y(20,-1);
vector<PI> X[20];
int dp[20][300000];

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        X[x].push_back(PI(y,z));
    }
    for(int i=0;i<N;++i){
        bool ok=true;
        for(auto u:X[0]){
            if(i<=u.first&&u.second==0){
                ok=false;
                break;
            }
        }
        if(!ok)continue;
        dp[0][1<<i]=1;
    }
    for(int i=0;i<N-1;++i){
        for(int j=0;j<(1<<N);++j){
            if(__builtin_popcount(j)!=i+1)continue;
            vector<int> cnt(20,0);
            for(int k=0;k<N;++k)if((j>>k)&1)cnt[k]++;
            for(int k=1;k<N;++k)cnt[k]+=cnt[k-1];
            for(int k=0;k<N;++k){
                if((j>>k)&1)continue;
                bool ok=true;
                for(auto u:X[i+1]){
                    int c=cnt[u.first];
                    if(k<=u.first)c++;
                    if(c>u.second){
                        ok=false;
                        break;
                    }
                }
                if(!ok)continue;
                dp[i+1][j+(1<<k)]+=dp[i][j];
            }
        }
    }
    cout<<dp[N-1][(1<<N)-1]<<endl;
}