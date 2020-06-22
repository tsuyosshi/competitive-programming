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

// st d=gcd(f,g) s*f+t*g=d

int f,g;
int s,t,d;

void EEA(){
    int r0=f,s0=1,t0=0;
    int r1=g,s1=0,t1=1;
    int r2,s2,t2;
    int step=1;
    while(r1!=0){
        step++;
        int q=r0/r1;
        r2=r0%r1;
        s2=s0-q*s1;
        t2=t0-q*t1;
        //cout<<"step"<<step<<endl;
        //printf("(%lld,%lld,%lld)-%lld(%lld,%lld,%lld)=(%lld,%lld,%lld)\n",r0,s0,t0,q,r1,s1,t1,r2,s2,t2);
        r0=r1,r1=r2;
        s0=s1,s1=s2;
        t0=t1,t1=t2;
    }
    d=r0,s=s0,t=t0;
}

signed main(){
    cin>>f>>g;
    EEA();
    cout<<s<<"f+"<<t<<"g="<<d<<endl;
}