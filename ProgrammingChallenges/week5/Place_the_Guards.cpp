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

const int MAX_V=200;

int T;
vector<int> G[MAX_V+5];
int vc[MAX_V+5];
bool visited[MAX_V+5];
bool ok=true;

int num;
int num_z;

void bfs1(int s){
    queue<int> que;
    que.push(s);
    vc[s]=0;
    while(!que.empty()&&ok){
        int q=que.front();
        que.pop();
        if(visited[q])continue;
        visited[q]=true;
        for(auto u:G[q]){
            if(vc[q]==vc[u]){
                ok=false;
                break;
            }
            vc[u]=!vc[q];
            que.push(u);
        }
    }
}

void bfs2(int s){
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int q=que.front();
        que.pop();
        if(visited[q])continue;
        num++;
        if(vc[q]==0)num_z++;
        visited[q]=true;
        for(auto u:G[q]){
            if(visited[u])continue;
            que.push(u);
        }
    }
}

signed main(){
    cin>>T;
    while (T--){
        ok=true;
        for(int i=0;i<MAX_V;++i){
            visited[i]=false;
            vc[i]=-1;
            G[i].clear();
        }
        int v,e;
        cin>>v>>e;
        for(int i=0;i<e;++i){
            int f,t;
            cin>>f>>t;
            G[f].push_back(t);
            G[t].push_back(f);
        }
        for(int i=0;i<v;++i){
            if(!ok)break;
            if(visited[i])continue;
            bfs1(i);
        }
        if(!ok)cout<<-1<<endl;
        else{
            int ans=0;
            for(int i=0;i<MAX_V;++i)visited[i]=false;
            for(int i=0;i<v;++i){
                if(visited[i])continue;
                num=0,num_z=0;
                bfs2(i);
                if(num==1)ans+=1;
                else ans+=min(num_z,num-num_z);
            }
            cout<<ans<<endl;
        }
    }
}