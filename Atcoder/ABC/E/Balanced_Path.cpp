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
int field_A[100][100],field_B[100][100];

int M=-1;
int c[100][100];
bool dp[100][100][30005];

int getId(int x){
    return x+M;
}

void init(){
    for(int i=0;i<100;++i)for(int j=0;j<100;++j)for(int k=0;k<30005;++k)dp[i][j][k]=false;
}

signed main(){
    init();
    cin>>H>>W;
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            cin>>field_A[y][x];
        }
    }
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            cin>>field_B[y][x];
        }
    }
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            c[y][x]=abs(field_A[y][x]-field_B[y][x]);
            chmax(M,(H+W)*c[y][x]);
        }
    }
    dp[0][0][getId(c[0][0])]=true;
    dp[0][0][getId(-c[0][0])]=true;
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            for(int k=-M;k<=M;++k){
                if(!dp[y][x][getId(k)])continue;
                dp[y+1][x][getId(k+c[y+1][x])]=true;
                dp[y+1][x][getId(k-c[y+1][x])]=true;
                dp[y][x+1][getId(k+c[y][x+1])]=true;
                dp[y][x+1][getId(k-c[y][x+1])]=true;
            }
        }
    }
    int ans=INF;
    for(int k=-M;k<=M;++k){
        if(!dp[H-1][W-1][getId(k)])continue;
        chmin(ans,(int)abs(k));
    }
    cout<<ans<<endl;
}
