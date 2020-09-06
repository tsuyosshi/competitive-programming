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

vector<edge> es;
vector<edge> tree;
int V,E;

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
}

int kruskal(){
    sort(es.begin(),es.end(),cmp);
    UnionFind uf(V+1);
    int res=0;
    for(int i=0;i<E;++i){
        edge e=es[i];
        if(!uf.same(e.from,e.to)){
            uf.unite(e.from,e.to);
            cout<<e.from<<" "<<e.to<<endl;
            res+=e.cost;
            tree.push_back(e);
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
    int w_min=kruskal();
    cout<<"minimun weight is "<<w_min<<endl;
}