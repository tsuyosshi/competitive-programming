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

const int mod=1000000007;
int N,M;
vector<int> E[200005];
int D[200005];
int dp[200005];

void bfs1(int s){
    queue<int> que;
    que.push(s);
    D[s]=0;
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:E[v]){
            if(D[u]>D[v]+1){
                D[u]=D[v]+1;
                que.push(u);
            }
        }
    } 
}

void bfs2(int s){
    queue<int> que;
    que.push(s);
    dp[s]=1;
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:E[v]){
            if(D[u]==D[v]+1){
                if(dp[u]==0)que.push(u);
                dp[u]+=dp[v];
                dp[u]%=mod;
            }
        }
    } 
}

signed main(){
    cin>>N>>M;
    for(int i=0;i<N;++i)D[i]=INF;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    bfs1(0);
    bfs2(0);
    cout<<dp[N-1]<<endl;
}