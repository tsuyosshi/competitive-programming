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

int A[4][4];
int house;

void bfs1(vector<vector<int>>& X,vector<vector<bool>>& visited,int sx,int sy,int c){
    queue<PI> que;
    que.push(PI(sx,sy));
    while(que.size()){
        int x=que.front().first,y=que.front().second;
        que.pop();
        visited[y][x]=true;
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=4||ny<0||ny>=4||visited[ny][nx]||X[ny][nx]!=c)continue;
            que.push(PI(nx,ny));
            visited[ny][nx]=true;
        }
    }
}

bool bfs2(vector<vector<int>>& X,vector<vector<bool>>& visited,int sx,int sy,int c){
    queue<PI> que;
    que.push(PI(sx,sy));
    bool surrounded=true;
    while(que.size()){
        int x=que.front().first,y=que.front().second;
        que.pop();
        visited[y][x]=true;
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=4||ny<0||ny>=4){
                surrounded=false;
                continue;
            }
            if(!visited[ny][nx]&&X[ny][nx]==c){
                que.push(PI(nx,ny));
                visited[ny][nx]=true;
            }
        }
    }
    return surrounded;
}

bool check(int bit){
    vector<vector<int>> X;
    vector<vector<bool>> visited;
    X.assign(4,vector<int>(4,0));
    visited.assign(4,vector<bool>(4,false));
    for(int y=0;y<4;++y){
        for(int x=0;x<4;++x){
            if((bit>>(y*4+x))&1)X[y][x]=1;
        }
    }
    bool flag=false;
    for(int y=0;y<4;++y){
        for(int x=0;x<4;++x){
            if(X[y][x]==1&&!visited[y][x]){
                if(flag){
                    return false;
                }
                else {
                    bfs1(X,visited,x,y,1);
                    flag=true;
                }                
            }
        }
    }
    for(int y=0;y<4;++y)for(int x=0;x<4;++x)visited[y][x]=false;
    for(int y=0;y<4;++y){
        for(int x=0;x<4;++x){
            if(X[y][x]==0&&!visited[y][x]){
                if(bfs2(X,visited,x,y,0)){
                    return false;   
                }
            }
        }
    }
    int cnt=0;
    for(int y=0;y<4;++y){
        for(int x=0;x<4;++x){
            if(X[y][x]==1&&A[y][x]==1)cnt++;
        }
    }
    if(cnt==house)return true;
    else return false;
}

signed main(){
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cin>>A[i][j];
            if(A[i][j]==1)house++;
        }
    }
    int ans=0;
    for(int i=0;i<(1<<16);++i){
        if(check(i))ans++;
    }
    cout<<ans<<endl;
}