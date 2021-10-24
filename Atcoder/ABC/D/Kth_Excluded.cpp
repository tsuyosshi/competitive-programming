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

int N,Q;
int A[100005];

signed main(){
    cin>>N>>Q;
    for(int i=0;i<N;++i)cin>>A[i];
    while(Q--){
        int K;
        cin>>K;
        int l=0,r=(1e18)*2+5;
        int mid;
        while(r-l>1){
            mid=(l+r)/2;
            int idx=lower_bound(A,A+N,mid)-A;
            if(mid-idx>K){
                r=mid;
            }
            else l=mid;
        }
        int idx=lower_bound(A,A+N,r)-A;
        if(r-idx==K)cout<<r<<endl;
        else cout<<l<<endl;
    }
}