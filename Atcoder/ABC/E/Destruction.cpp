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

class UnionFind {
public:
    vector<int> par;

    UnionFind(int N):par(N){
        for(int i=0;i<N;i++)par[i]=i;
    }

    int root(int x){
        if (par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if (rx==ry) return;
        par[rx]=ry;
    }

    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
};

struct edge {
    int from,to,cost;
    edge() {}
    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

bool cmp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

int N,M;
vector<edge> E;

int kruskal(vector<edge> &es){
    sort(es.begin(),es.end(),cmp);
    UnionFind uf(N+1);
    int res=0;
    for(int i=0;i<es.size();++i){
        edge e=es[i];
        if(!uf.same(e.from,e.to)){
            uf.unite(e.from,e.to);
            res+=e.cost;
        }
    }
    return res;
}


signed main(){
    cin>>N>>M;
    int sum=0;
    for(int i=0;i<M;++i){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        c=max(c,0ll);
        E.push_back(edge(a,b,c));
        E.push_back(edge(b,a,c));
        sum+=c;
    }
    cout<<sum-kruskal(E)<<endl;
}