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

int N,K;
int c[300005];
map<int,int> mp;

signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>c[i];
    for(int i=0;i<K;++i)mp[c[i]]++;
    int ma=(int)mp.size();
    for(int i=1;i<=N-K;++i){
        mp[c[i-1]]--;
        mp[c[i+K-1]]++;
        if(mp[c[i-1]]==0)mp.erase(c[i-1]);
        chmax(ma,(int)mp.size());
    }
    cout<<ma<<endl;
}