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

int N,M;
vector<PI> E[405];
int d[405][405];
int ans;

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        E[a].push_back(PI(b,c));
    }
    for(int i=0;i<N;++i)for(int j=0;j<N;++j)d[i][j]=INF;
    for(int i=0;i<N;++i)for(auto u:E[i])d[i][u.first]=u.second;
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(i==j)continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                if(d[i][j]!=INF)ans+=d[i][j];
            }
        }
    }
    cout<<ans<<endl;
}