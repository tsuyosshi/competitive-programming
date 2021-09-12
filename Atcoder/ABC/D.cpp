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

int N;
vector<PI> V;
map<PI,bool> mp;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int x,y;
        cin>>x>>y;
        V.push_back(PI(x,y));
        mp[PI(x,y)]=true;
    }
    int ans=0;
    sort(V.begin(),V.end());
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            int sx=V[i].first,sy=V[i].second;
            int tx=V[j].first,ty=V[j].second;
            if(sx==tx||sy==ty)continue;
            if(sy<ty){
                if(mp.find(PI(tx,sy))!=mp.end()&&mp.find(PI(sx,ty))!=mp.end())ans++;
            }
        }
    }
    cout<<ans<<endl;
}