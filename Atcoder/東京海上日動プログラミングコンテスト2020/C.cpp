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

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int MAX_N=200000;
int N,K;
int A[MAX_N+5];

int res[MAX_N+5];

signed main(){
    cin>>N>>K;
    for(int i=1;i<=N;++i)cin>>A[i];
    for(int i=0;i<K;++i){
        int minA=INF;
        for(int j=1;j<=N;++j){
            int l=max(1ll,j-A[j]),r=min(N,j+A[j]);
            res[l]++;
            res[r+1]--;
        }
        for(int j=1;j<=N;++j)res[j]+=res[j-1];
        for(int j=1;j<=N;++j){
            A[j]=min(N,res[j]);
            chmin(minA,A[j]);
            res[j]=0;
        }
        if(minA==N)break;
    }
    for(int i=1;i<=N;++i)cout<<A[i]<<" ";
    cout<<endl;
}