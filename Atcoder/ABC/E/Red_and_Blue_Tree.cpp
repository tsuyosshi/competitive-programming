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

int N,M,K;
int A[105];
vector<int> T[1005];
map<PI,int> E;
int cnt[1005];

vector<int> bfs(int s,int t){
    queue<int> que1;
    queue<vector<int>> que2;
    vector<bool> visited(1005,false);
    vector<int> tmp;
    que1.push(s);
    que2.push(tmp);
    visited[s]=true;
    while(true){
        int v=que1.front();
        vector<int> q=que2.front();
        que1.pop();
        que2.pop();
        if(v==t)return q;
        for(auto u:T[v]){
            if(visited[u])continue;
            vector<int> n(q);
            int e=E[PI(min(u,v),max(u,v))];
            n.push_back(e);
            visited[u]=true;
            que1.push(u);
            que2.push(n);
        }
    }
}

const int mod=998244353;
map<PI,int> mem;

int calc(int n,int k){
    if(mem.find(PI(n,k))!=mem.end())return mem[PI(n,k)];
    if(n==N){
        if(k==K)return 1;
        else return 0;
    }
    int res=0;
    res+=calc(n+1,k+cnt[n]);
    res%=mod;
    res+=calc(n+1,k-cnt[n]);
    res%=mod;
    return mem[PI(n,k)]=res;
}

int modPow(int a,int n) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

signed main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;++i){
        cin>>A[i];
        A[i]--;
    }
    for(int i=0;i<N-1;++i){
        int u,v;
        cin>>u>>v;
        u--,v--;
        T[u].push_back(v);
        T[v].push_back(u);
        E[PI(min(u,v),max(u,v))]=i;
    }
    for(int i=0;i<M-1;++i){
        //cout<<i<<endl;
        //cout<<"i : "<<A[i]<<" "<<A[i+1]<<endl;
        vector<int> path=bfs(A[i],A[i+1]);
        for(auto u:path){
            //cout<<u<<endl;
            cnt[u]++;
        }
    }
    //for(int u=0;u<N;++u)cout<<cnt[u]<<endl;
    int ans=calc(0,0);

    cout<<(ans*modPow(2,mod-2))%mod<<endl;
}