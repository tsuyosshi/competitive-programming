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
int A[200005];
vector<int> v;
int ans;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    sort(A,A+N,greater<int>());
    if(N<=3){
        for(int i=0;i<N-1;++i)ans+=A[i];
        cout<<ans<<endl;
    }
    else {
        for(int i=0;i<2;++i){
            ans+=A[i];
        }
        for(int i=0;i<3;++i)v.push_back(min(A[i],A[(i+1)%3]));
        int t=3;
        while(t<N){
            vector<int> nv;
            for(int i=0;i<v.size();++i){
                if(t+i>=N)break;
                ans+=v[i];
            }
            for(int i=0;i<v.size();++i){
                if(t+i>=N)break;
                nv.push_back(A[t+i]);
                nv.push_back(A[t+i]);
            }
            t+=v.size();
            v.clear();
            for(int i=0;i<nv.size();++i)v.push_back(nv[i]);
        }
        cout<<ans<<endl;
    }
}