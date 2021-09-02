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

int H,W;
string S[505];
int d[505][505];

signed main(){
    cin>>H>>W;
    for(int i=0;i<H;++i)cin>>S[i];
    for(int y=0;y<H;++y)for(int x=0;x<W;++x)d[y][x]=INF;
    queue<PI> que;
    que.push(PI(0,0));
    d[0][0]=0;
    while(que.size()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        for(int i=0;i<4;++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=W||ny<0||ny>=H||S[ny][nx]=='#')continue;
            if(d[ny][nx]>d[y][x]){
                que.push(PI(nx,ny));
                d[ny][nx]=d[y][x];
            }
        }
        for(int ny=y-2;ny<=y+2;++ny){
            for(int nx=x-2;nx<=x+2;++nx){
                if(nx<0||nx>=W||ny<0||ny>=H)continue;
                if(abs(x-nx)+abs(y-ny)==4)continue;
                if(d[ny][nx]>d[y][x]+1){
                    que.push(PI(nx,ny));
                    d[ny][nx]=d[y][x]+1;
                }
            }
        }
    }
    cout<<d[H-1][W-1]<<endl;
}