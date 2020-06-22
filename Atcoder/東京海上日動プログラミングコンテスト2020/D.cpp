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

const int MAX_N=18;

int N,Q;
int V[(1<<MAX_N)+5],W[(1<<MAX_N)+5];

vector<PI> ps;

int ance(int v,int n){
    int p=((v>>n));
    return p;
}

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)scanf("%lld%lld",&V[i],&W[i]);
    cin>>Q;
    while(Q--){
        int v,L;
        scanf("%lld%lld",&v,&L);
        int n=log2(N+1);
        int n2=n/2;
        for(int i=0;i<(1<<n2);++i){
            int sw=0,sv=0;
            for(int j=0;j<n2;++j){
                if((i>>j)&1){
                    int p=ance(v,j)-1;
                    sw+=W[p];
                    sv+=V[p];
                }
            }
            ps.push_back(PI(sw,sv));
        }
        sort(ps.begin(),ps.end());
        int res=0;
        for(int i=0;i<(1<<(n-n2));++i){
            int sw=0,sv=0;
            for(int j=0;j<n-n2;++j){
                if((i>>j)&1){
                    int p=ance(v,n2+j)-1;
                    sw+=W[p];
                    sv+=V[p];
                }
            }
            if(sw<=L){
                int tv=(lower_bound(ps.begin(),ps.end(),PI(L-sw,INF))-1)->second;
                chmax(res,sv+tv);
            }
        }
        cout<<res<<endl;
        ps.clear();
    }
}