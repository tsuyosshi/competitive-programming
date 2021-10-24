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
vector<PI> v;
int imos[2000005];
vector<int> p(20000005);
int ans[200005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int a,b;
        cin>>a>>b;
        v.push_back(PI(a-1,1));
        v.push_back(PI(a,0));
        v.push_back(PI(a+b-1,1));
        v.push_back(PI(a+b,2));
    }
    sort(v.begin(),v.end());
    int t=0;
    p[0]=v[0].first;
    if(v[0].second==0)imos[0]++;
    else if(v[0].second==2)imos[0]--;
    for(int i=1;i<v.size();++i){
        if(v[i].first!=v[i-1].first){
            t++;
            p[t]=v[i].first;
        }
        if(v[i].second==0)imos[t]++;
        if(v[i].second==2)imos[t]--;
    }
    for(int i=1;i<=t;++i)imos[i]+=imos[i-1];
    for(int i=1;i<=t;++i){
        //cout<<imos[i]<<" "<<p[i]<<endl;
        ans[imos[i]]+=p[i]-p[i-1];
    }
    for(int i=1;i<=N;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}