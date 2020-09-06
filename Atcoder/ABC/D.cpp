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

struct Pos{
    int x,y;
    Pos(int x,int y):x(x),y(y){}
};

int H,W;
int Ch,Cw;
int Dh,Dw;
string field[1005];
int s[1005][1005];
int d[1000005];
bool visited[1005][1005];
int id;
set<int> E[1000005];


void init(){
    id=0;
    for(int i=0;i<1000003;++i)d[i]=INF;
    for(int i=0;i<1003;++i){
        for(int j=0;j<1003;++j){
            s[i][j]=-1;
            visited[i][j]=false;
        }
    }
}

void bfs1(int sx,int sy){
    queue<Pos> que;
    que.push(Pos(sx,sy));
    s[sy][sx]=id;
    visited[sy][sx]=true;
    while(que.size()){
        Pos p=que.front();
        que.pop();
        for(int i=0;i<4;++i){
            int nx=p.x+dx[i],ny=p.y+dy[i];
            if(nx<0||nx>=W||ny<0||ny>=H)continue;
            if(visited[ny][nx])continue;
            if(s[ny][nx]!=-1)continue;
            if(field[ny][nx]=='#')continue;
            que.push(Pos(nx,ny));
            s[ny][nx]=id;
            visited[ny][nx]=true;
        }
    }
    id++;
}

void bfs2(int s){
    queue<int> que;
    que.push(s);
    d[s]=0;
    while(que.size()){
        int p=que.front();
        que.pop();
        for(auto u:E[p]){
            if(d[u]!=INF)continue;
            que.push(u);
            d[u]=d[p]+1;
        }
    }
}

signed main(){
    init();
    cin>>H>>W;
    cin>>Ch>>Cw;
    cin>>Dh>>Dw;
    Ch--,Cw--;
    Dh--,Dw--;
    for(int i=0;i<H;++i)cin>>field[i];
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            if(field[y][x]=='#')continue;
            if(s[y][x]!=-1)continue;
            bfs1(x,y);
        }
    }
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            if(field[y][x]=='#')continue;
            for(int i=-2;i<=2;++i){
                for(int j=-2;j<=2;++j){
                    int nx=x+i,ny=y+j;
                    if(nx<0||nx>=W||ny<0||ny>=H)continue;
                    if(s[ny][nx]==s[y][x])continue;
                    if(field[ny][nx]=='#')continue;
                    E[s[y][x]].insert(s[ny][nx]);
                    E[s[ny][nx]].insert(s[y][x]);
                }
            }
        }
    }
    bfs2(s[Ch][Cw]);
    if(d[s[Dh][Dw]]==INF)cout<<-1<<endl;
    else cout<<d[s[Dh][Dw]]<<endl;
}