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
vector<PI> V;

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,c;
        cin>>a>>c;
        V.push_back(PI(c,a));
    }
    sort(V.begin(),V.end());
    int ans=0;
    int nt;
    nt=__gcd(N,V[0].second);
    ans+=V[0].first*(N-nt);
    for(int i=1;i<M;++i){
        int n=__gcd(nt,V[i].second);
        ans+=V[i].first*(nt-n);
        nt=n;
    }
    if(nt==1)cout<<ans<<endl;
    else cout<<-1<<endl;
}