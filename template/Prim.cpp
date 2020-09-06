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

struct edge {
    int from,to,cost;
    edge() {}
    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

vector<edge> es;
vector<edge> tree;
int V,E;
int cost[1005][1005];
int mincost[1005];
bool used[1005];

void init(){
    es.push_back(edge(1,2,4));
    es.push_back(edge(1,3,7));
    es.push_back(edge(1,4,6));
    es.push_back(edge(2,1,4));
    es.push_back(edge(2,3,6));
    es.push_back(edge(2,5,7));
    es.push_back(edge(3,1,7));
    es.push_back(edge(3,2,6));
    es.push_back(edge(3,4,7));
    es.push_back(edge(3,5,8));
    es.push_back(edge(4,1,6));
    es.push_back(edge(4,3,7));
    es.push_back(edge(4,5,9));
    es.push_back(edge(4,6,9));
    es.push_back(edge(4,7,8));
    es.push_back(edge(5,2,7));
    es.push_back(edge(5,3,8));
    es.push_back(edge(5,4,9));
    es.push_back(edge(5,6,2));
    es.push_back(edge(5,8,2));
    es.push_back(edge(6,4,9));
    es.push_back(edge(6,5,2));
    es.push_back(edge(6,7,5));
    es.push_back(edge(6,8,5));
    es.push_back(edge(7,4,8));
    es.push_back(edge(7,6,5));
    es.push_back(edge(7,8,3));
    es.push_back(edge(8,5,2));
    es.push_back(edge(8,6,5));
    es.push_back(edge(8,7,3));
    for(int i=0;i<1005;++i)for(int j=0;j<1005;++j)cost[i][j]=INF;
    for(auto e:es)cost[e.from-1][e.to-1]=e.cost;
}

int prim(){
    for(int i=0;i<V;++i){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;++u){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        cout<<v+1<<" "<<mincost[v]<<endl;
        for(int u=0;u<V;++u){
            chmin(mincost[u],cost[v][u]);
        }
    }
    return res;
}

signed main(){
    init();
    V=8,E=es.size();
    int sum_w=0;
    for(int i=0;i<E;++i)sum_w+=es[i].cost;
    cout<<"sum of weights is "<<sum_w/2<<endl;
    int w_min=prim();
    cout<<"minimun weight is "<<w_min<<endl;
}