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

int N,M,K;
int A[200005],B[200005];
int sumA[200005],sumB[200005];
int ans;
int T;

signed main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<M;++i)cin>>B[i];
    sumA[0]=0,sumB[0]=0;
    for(int i=1;i<N+1;++i)sumA[i]=sumA[i-1]+A[i-1];
    for(int i=1;i<M+1;++i)sumB[i]=sumB[i-1]+B[i-1];
    int ans=0;
    for(int i=0;i<N+1;++i){
        if(K<sumA[i])break;
        int C=K-sumA[i];
        int id=upper_bound(sumB,sumB+M+1,C)-sumB-1;
        if(sumA[i]+sumB[id]<=K)chmax(ans,i+id);
    }
    cout<<ans<<endl;
}