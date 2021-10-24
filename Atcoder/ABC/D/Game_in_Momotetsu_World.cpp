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
vector<string> field;
int mem[2005][2005][2];

int calc(int x,int y,int p){
    if(mem[y][x][p]!=INF)return mem[y][x][p];
    if(x==W-1&&y==H-1)return 0;
    int res=(p==0 ? -INF : INF);
    if(x+1<W){
        int c=(field[y][x+1]=='+' ? 1: -1);
        if(p==0)chmax(res,calc(x+1,y,!p)+c);
        else chmin(res,calc(x+1,y,!p)-c);
    }
    if(y+1<H){
        int c=(field[y+1][x]=='+' ? 1: -1);
        if(p==0)chmax(res,calc(x,y+1,!p)+c);
        else chmin(res,calc(x,y+1,!p)-c);
    }
    return mem[y][x][p]=res;
}

signed main(){
    for(int i=0;i<2005;++i)for(int j=0;j<2005;++j)mem[i][j][0]=mem[i][j][1]=INF;
    cin>>H>>W;
    for(int i=0;i<H;++i){
        string s;
        cin>>s;
        field.push_back(s);
    }
    int d=calc(0,0,0);
    if(d>0)cout<<"Takahashi"<<endl;
    else if(d<0)cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
}
