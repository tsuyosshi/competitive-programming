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

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int MAX_N=50000;

int T;
int G[MAX_N+5];

int res;
int mem[MAX_N+5];
bool visited[MAX_N+5];

void init(){
    res=0;
    for(int i=0;i<MAX_N;++i){
        mem[i]=-1;
        visited[i]=false;
    }
}

int dfs(int n){
    if(visited[n])return 0;
    visited[n]=true;
    res=dfs(G[n])+1;
    visited[n]=false;
    return mem[n]=res;
}

signed main(){
    cin>>T;
    for(int t=0;t<T;++t){
        int N;
        cin>>N;
        for(int i=0;i<N;++i){
            int u,v;
            cin>>u>>v;
            u--,v--;
            G[u]=v;
        }
        PI ans=PI(0,INF);
        init();
        for(int i=0;i<N;++i){
            if(mem[i]!=-1)continue;
            else {
                int cnt=dfs(i);
                if(ans.first<cnt)ans=PI(cnt,i);
            }
        }
        cout<<"Case "<<t+1<<": ";
        cout<<ans.second+1<<endl;
    }
}