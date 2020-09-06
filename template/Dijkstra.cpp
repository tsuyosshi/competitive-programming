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
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};

vector<edge> G[200005];
int d[200005];

void input(){
    G['s'].push_back(edge('a',4));
    G['s'].push_back(edge('b',6));
    G['a'].push_back(edge('b',1));
    G['a'].push_back(edge('c',6));
    G['b'].push_back(edge('b',3));
    G['b'].push_back(edge('c',4));
    G['b'].push_back(edge('d',2));
    G['c'].push_back(edge('d',4));
    G['d'].push_back(edge('c',1));
}

void dijkstar(int s){
    for(int i=0;i<200005;++i)d[i]=INF;
    priority_queue<PI,vector<PI>,greater<PI>> pq;
    d[s]=0;
    pq.push(PI(0,s));
    while(pq.size()){
        PI p=pq.top();
        pq.pop();
        int v=p.second;
        cout<<"v : "<<(char)(v)<<endl;
        cout<<"dist : "<<d[v]<<endl; 
        cout<<"p : "<<p.first<<endl;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();++i){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                pq.push(PI(d[e.to],e.to));
            }
        }
    }
}

signed main(){
    input();
    dijkstar('s');
    cout<<"All done"<<endl;
    for(int i=0;i<100005;++i){
        if(d[i]!=INF){
            cout<<(char)(i)<<" : "<<d[i]<<endl;
        }
    }
}