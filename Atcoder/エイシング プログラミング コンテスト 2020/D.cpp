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
string X;

int modPow(int a, int n, int mod) {
    if(n==0)return 1%mod;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1,mod))%mod;
    int t=modPow(a,n/2,mod);
    return (t*t)%mod;
}

int calc(int x,int depth){
    int m=0;
    int d=0;
    if(x==0)return depth;
    for(int i=60;i>=0;--i){
        if((x>>i)&1)d++;
    }
    if(d==0)return depth;
    for(int i=60;i>=0;--i){
        if((x>>i)&1){
            m+=modPow(2,i,d);
            m%=d;
        }
    }
    if(m==0)return depth+1;
    return calc(m,depth+1);
}

int maesyori(string x,int mod){
    int ret=0;
    int m=0;
    for(int i=x.size()-1;i>=0;--i){
        if(x[i]=='1'){
            m+=modPow(2,x.size()-1-i,mod);
            m%=mod;
        }
    }
    if(m==0)return 0;
    for(int i=60;i>=0;--i){
        if((m>>i)&1)ret+=modPow(2,i,mod);
    }
    return ret;
}

signed main(){
    cin>>N;
    int d=0;
    for(int i=0;i<N;++i){
        char x;
        cin>>x;
        X+=x;
        if(x=='1')d++;
    }
    int pls=maesyori(X,d+1);
    int mns=maesyori(X,max(d-1,1ll));
    for(int i=0;i<N;++i){
        int x;
        if(X[i]=='0'){
            x=pls+modPow(2,X.size()-1-i,d+1);
            x%=(d+1);
            cout<<calc(x,0)+1<<endl;
        }
        else{
            if(d-1==0)cout<<0<<endl;
            else {
                x=mns-modPow(2,X.size()-1-i,d-1);
                x=(x+d-1)%(d-1);
                cout<<calc(x,0)+1<<endl;
            }
        }
    }
}