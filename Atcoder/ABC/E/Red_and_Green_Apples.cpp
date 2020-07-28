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
 
const int mod=1000000007;
 
int X,Y,A,B,C;
int p[100005],q[100005],r[100005];
int ans;

signed main(){
    cin>>X>>Y>>A>>B>>C;
    for(int i=0;i<A;++i)cin>>p[i];
    for(int i=0;i<B;++i)cin>>q[i];
    for(int i=0;i<C;++i)cin>>r[i];
    sort(p,p+A,greater<int>());
    sort(q,q+B,greater<int>());
    sort(r,r+C,greater<int>());
    priority_queue<int,vector<int>,greater<int>> pq;
    int ph=0,qh=0,rh=0;
    while(pq.size()<X+Y){
        if(qh>=Y||(p[ph]>=q[qh]&&ph<X)){
            pq.push(p[ph]);
            ph++;
        }
        else {
            pq.push(q[qh]);
            qh++;
        }
    }
    while(pq.size()){
        int v=pq.top();
        if(v>r[rh])break;
        pq.pop();
        ans+=r[rh];
        rh++;
    }
    while(pq.size()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}
