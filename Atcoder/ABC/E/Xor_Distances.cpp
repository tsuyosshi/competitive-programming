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

const int mod=1e9+7;
int N;
vector<vector<PI>> T(200005);
int dist[200005];
int d0[200005],d1[200005]; // i桁目が 0 or 1 のdistの数

int modPow(int a, int n) {
    if(n<=0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

void dfs(int n){
    for(auto u:T[n]){
        if(dist[u.first]!=-1)continue;
        dist[u.first]=dist[n]^u.second;
        dfs(u.first);
    }
}

signed main(){
    cin>>N;
    for(int i=0;i<N-1;++i){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        T[u].push_back(PI(v,w));
        T[v].push_back(PI(u,w));
    }
    fill(dist,dist+N,-1);
    dist[0]=0;
    dfs(0);
    for(int i=0;i<N;++i){
        for(int j=0;j<60;++j){
            if((dist[i]>>j)&1)d1[j]++;
            else d0[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<60;++j){
            if((dist[i]>>j)&1){
                ans+=d0[j]*modPow(2,j);
                ans%=mod;
            }
            else {
                ans+=d1[j]*modPow(2,j);
                ans%=mod;
            }
        }
    }
    cout<<(ans*modPow(2,mod-2))%mod<<endl;
}       