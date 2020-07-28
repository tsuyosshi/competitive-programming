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

int N,K;
int A[200005];
int mlt[200005];
int mlt_inv[200005];
int ans=-INF;

vector<int> pls;
vector<int> mns;

int modPow(int a, int n) {
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

signed main(){
    for(int i=0;i<200005;++i){
        mlt[i]=1;
        mlt_inv[i]=1;
    }
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>A[i];
    sort(A,A+N);
    for(int i=0;i<N;++i){
        if(A[i]>=0)pls.push_back(A[i]);
        else mns.push_back(A[i]);
    }
    int ph=0,mh=0;
    int cnt=0;
    int res=1;
    while(cnt<K){
        if(cnt+2>K||mh==mns.size()-1){
            res*=pls[ph];
            ph++;
            cnt++;
        }
        else if(ph==pls.size()-1){
            res*=mns[mh]*mns[mh+1];
            mh+=2;
            cnt+=2;
        }
        else {
            if(K-ph==2&&ph==pls.size()-2){
                res*=mns[mh]*mns[mh+1];
                mh+=2;
                cnt+=2;
            }
            else if(mns[mh]*mns[mh+1]<pls[ph]*pls[ph+1])
        }  
    }
}