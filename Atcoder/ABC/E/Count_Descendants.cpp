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

int N,Q;
vector<vector<int>> T(200005);
int in[200005];
int out[200005];
vector<int> depth(200005);
vector<vector<int>> mem(200005);

int t=0;
void dfs(int v){
    //cout<<v<<endl;
    in[v]=t;
    mem[depth[v]].push_back(in[v]);
    t++;
    for(auto u:T[v]){
        depth[u]=depth[v]+1;
        dfs(u);
    }
    out[v]=t;
    t++;
}

signed main(){
    cin>>N;
    for(int i=1;i<N;++i){
        int p;
        cin>>p;
        p--;
        T[p].push_back(i);
    }
    depth[0]=0;
    dfs(0);
    cin>>Q;
    while(Q--){
        int u,d;
        cin>>u>>d;
        u--;
        int l=lower_bound(mem[d].begin(),mem[d].end(),in[u])-mem[d].begin();
        int r=upper_bound(mem[d].begin(),mem[d].end(),out[u])-mem[d].begin()-1;
        if(l>r)cout<<0<<endl;
        else cout<<r-l+1<<endl;
    }
}