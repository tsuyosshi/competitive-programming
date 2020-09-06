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
string field[25];
int d[25][25];

void init(){
    for(int i=0;i<25;++i)for(int j=0;j<25;++j)d[i][j]=INF;
}

int bfs(Pos s,Pos e){
    init();
    queue<Pos> que;
    que.push(Pos(s.x,s.y));
    d[s.y][s.x]=0;
    while(que.size()){
        Pos p=que.front();
        que.pop();
        for(int i=0;i<4;++i){
            int nx=p.x+dx[i],ny=p.y+dy[i];
            if(nx<0||nx>=W||ny<0||ny>=H)continue;
            if(d[ny][nx]!=INF||field[ny][nx]=='#')continue;
            que.push(Pos(nx,ny));
            d[ny][nx]=d[p.y][p.x]+1;
        }
    }
    return d[e.y][e.x];
}

signed main(){
    cin>>H>>W;
    for(int i=0;i<H;++i)cin>>field[i];
    int ans=0;
    for(int sy=0;sy<H;++sy){
        for(int sx=0;sx<W;++sx){
            for(int ey=0;ey<H;++ey){
                for(int ex=0;ex<W;++ex){
                    if(field[sy][sx]=='#'||field[ey][ex]=='#')continue;
                    chmax(ans,bfs(Pos(sx,sy),Pos(ex,ey)));
                }
            }
        }
    }
    cout<<ans<<endl;
}