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
int S,T;
vector<int> G[100005];
int d[100005][3]; 

void init(){
    for(int i=0;i<100005;++i)for(int j=0;j<3;++j)d[i][j]=-1;
}

void bfs(int s){
    queue<PI> que;
    que.push(PI(s,0));
    d[s][0]=0;
    while(que.size()){
        PI v=que.front();
        que.pop();
        for(auto u:G[v.first]){
            PI n=PI(u,(v.second+1)%3);
            if(d[u][n.second]!=-1)continue;
            que.push(n);
            d[u][n.second]=d[v.first][v.second]+1;
        }
    }
}

signed main(){
    init();
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int u,v;
        cin>>u>>v;
        u--,v--;
        G[u].push_back(v);
    }
    cin>>S>>T;
    S--,T--;
    bfs(S);
    if(d[T][0]==-1)cout<<-1<<endl;
    else cout<<d[T][0]/3<<endl;
}
