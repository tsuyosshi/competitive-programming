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

int N,M;
vector<vector<int>> P(200005);
vector<int> deg(200005,0);

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        P[a].push_back(b);
        deg[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<N;++i)if(deg[i]==0)que.push(i);
    vector<int> ans;
    vector<bool> visited(N,false);
    while(que.size()){
        int v=que.top();
        que.pop();
        ans.push_back(v);
        visited[v]=true;
        for(auto u:P[v]){
            if(deg[u]>0)deg[u]--;
            if(deg[u]==0&&!visited[u]){
                que.push(u);
                visited[u]=true;
            }
        }
    }
    if(ans.size()!=N)cout<<-1<<endl;
    else {
        for(auto u:ans)cout<<u+1<<" ";
        cout<<endl;
    }
}