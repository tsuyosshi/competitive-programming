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

struct Pos{
    int x,y;
    Pos(){}
    Pos(int x,int y):x(x),y(y){}
};

int N;
vector<Pos> pos;
int p[20];
int K;
vector<int> lx,ly;

int calc(int n){
    if(n==N&&lx.size()+ly.size()!=K)return INF;
    if(lx.size()+ly.size()==K){
        int res=0;
        for(int i=0;i<N;++i){
            int dist_min=INF;
            for(auto u:lx){
                int dist=abs(pos[i].x-pos[u].x);
                chmin(dist_min,dist);
            }
            for(auto u:ly){
                int dist=abs(pos[i].y-pos[u].y);
                chmin(dist_min,dist);
            }
            chmin(dist_min,abs(pos[i].x));
            chmin(dist_min,abs(pos[i].y));
            res+=p[i]*dist_min;
        }
        return res;
    }
    else {
        int res=INF;
        res=min(res,calc(n+1));
        lx.push_back(n);
        res=min(res,calc(n+1));
        lx.pop_back();
        ly.push_back(n);
        res=min(res,calc(n+1));
        ly.pop_back();
        return res;
    }
}

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        pos.push_back(Pos(x,y));
        cin>>p[i];
    }
    for(int k=0;k<=N;++k){
        K=k;
        cout<<calc(0)<<endl;
        lx.clear();
        ly.clear();
    }
}