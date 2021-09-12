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

int N,Q;
vector<int> E[100005];
bool visited[100005];
int dist[100005];

void bfs(int s){
    queue<int> que;
    que.push(s);
    dist[s]=0;
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:E[v]){
            if(dist[u]!=INF)continue;
            dist[u]=dist[v]+1;
            que.push(u);
        }
    }
}

signed main(){
    cin>>N>>Q;
    for(int i=0;i<N-1;++i){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i=0;i<N;++i)dist[i]=INF;
    bfs(0);
    while(Q--){
        int c,d;
        cin>>c>>d;
        c--;
        d--;
        if(abs(dist[d]-dist[c])%2==0)cout<<"Town"<<endl;
        else cout<<"Road"<<endl;
    }
}