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
int A[100005],B[100005];
vector<PII> G[100005];
int dist[100005][2];

void dijkstar(int s){
    for(int i=0;i<100005;++i)dist[i][0]=dist[i][1]=INF;
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    dist[s][0]=dist[s][1]=0;
    pq.push(PII(0,PI(s,0)));
    pq.push(PII(0,PI(s,1)));
    while(pq.size()){
        PII p=pq.top();
        pq.pop();
        int T=p.first;
        int v=p.second.first;
        int w=p.second.second;
        if(dist[v][w]<T)continue;
        for(int i=0;i<G[v].size();++i){
            PII e=G[v][i];
            int to=e.first,c=e.second.first,d=e.second.second;
            int cost=c+d/(T+1);
            // 即通行
            if(dist[to][0]>dist[v][w]+cost){
                dist[to][0]=dist[v][w]+cost;
                pq.push(PII(dist[to][0],PI(to,0)));
            }
            // 待機
            // (t-T)+[D_i/(t+1)] の増加率が正となるtを求める
            if(T<=sqrt(d)){
                int t=sqrt(d);
                int cost=(t-T)+c+d/(t+1);
                if(dist[to][1]>dist[v][w]+cost){
                    dist[to][1]=dist[v][w]+cost;
                    pq.push(PII(dist[to][1],PI(to,1)));
                }
            }
        }
    }
}


signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        G[a].push_back(PII(b,PI(c,d)));
        G[b].push_back(PII(a,PI(c,d)));
    }
    dijkstar(0);
    int ans=min(dist[N-1][0],dist[N-1][1]);
    if(ans!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;
}