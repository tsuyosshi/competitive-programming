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

int N;
int X,Y;
int A[305],B[305];
int mem[305][305][305];

int calc(int n,int x_rem,int y_rem){
    if(mem[n][x_rem][y_rem]!=-1)return mem[n][x_rem][y_rem];
    if(n==N){
        if(x_rem==0&&y_rem==0)return 0;
        else return INF;
    }
    int res=INF;
    res=min(calc(n+1,max(0ll,x_rem-A[n]),max(0ll,y_rem-B[n]))+1,calc(n+1,x_rem,y_rem));
    return mem[n][x_rem][y_rem]=res;
}

signed main(){
    for(int i=0;i<305;++i)for(int j=0;j<305;++j)for(int k=0;k<305;++k)mem[i][j][k]=-1;
    cin>>N>>X>>Y;
    for(int i=0;i<N;++i)cin>>A[i]>>B[i];
    int ans=calc(0,X,Y);
    if(ans!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;
}