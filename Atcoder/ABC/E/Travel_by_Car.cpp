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

int N,M,L;
int Q;

int d[305][305];
int u[305][305];
int remain[305];

void init(){
    for(int i=0;i<305;++i)for(int j=0;j<305;++j){
        if(i==j)d[i][j]=0;
        else d[i][j]=INF;
        u[i][j]=INF;
    }
}

void warshall_floyd1(){
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                chmin(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

void warshall_floyd2(){
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                chmin(u[i][j],u[i][k]+u[k][j]);
            }
        }
    }
}

signed main(){
    init();
    cin>>N>>M>>L;
    for(int i=0;i<M;++i){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        d[a][b]=d[b][a]=c;
    }
    warshall_floyd1();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(L<d[i][j])continue;
            u[i][j]=1;
        }
    }
    warshall_floyd2();
    cin>>Q;
    while(Q--){
        int s,t;
        cin>>s>>t;
        s--,t--;
        int cost=u[s][t];
        if(cost==INF)cout<<-1<<endl;
        else cout<<cost-1<<endl;
    }
}
