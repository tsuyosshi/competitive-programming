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

int modPow(int a, int n, int mod) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1,mod))%mod;
    int t=modPow(a,n/2,mod);
    return (t*t)%mod;
}

int K;

signed main(){
    cin>>K;
    int mod=0;
    int t=0;
    while(true){
        mod+=7*modPow(10,t,K);
        mod%=K;
        t++;
        if(mod==0){
            cout<<t<<endl;
            return 0;
        }
        if(t>1000000){
            cout<<-1<<endl;
            return 0;
        }
    }
}