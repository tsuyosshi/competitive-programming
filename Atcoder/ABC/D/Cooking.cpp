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

/*
int N;
int T[105];
map<PI,int> mem;

int calc(int n,int t){
    if(mem.find(PI(n,t))!=mem.end())return mem[PI(n,t)];
    if(n==N)return abs(t);
    int res=min(calc(n+1,t+T[n]),calc(n+1,t-T[n]));
    return mem[PI(n,t)]=res;
}

signed main(){
    cin>>N;
    int S=0;
    for(int i=0;i<N;++i){
        cin>>T[i];
        S+=T[i];
    }
    int K=calc(0,0);
    cout<<(S+K)/2<<endl;
}
*/

int N;
int T[105];
int dp[105][100005];

signed main(){
    cin>>N;
    int S=0;
    for(int i=0;i<N;++i){
        cin>>T[i];
        S+=T[i];
    }
    dp[0][T[0]]=1;
    for(int i=1;i<N;++i){
        for(int j=0;j<100005;++j){
            if(j-T[i]<0)continue;
            dp[i][j]+=dp[i-1][j-T[i]]+dp[i-1][j];
        }
    }
    for(int i=S/2;i<100005;++i){
        if(dp[N-1][i]!=0){
            cout<<max(i,S-i)<<endl;
            return 0;
        }
    }
}