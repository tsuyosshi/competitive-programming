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

const int mod=998244353;

int modPow(int a,int n) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

class BIT {
public:
    vector<int> bit;
    int M;

    BIT(){}

    BIT(int M):
        bit(vector<int>(M+1,0)),M(M){}

    int sum(int i) {
        if(!i)return 0;
        return bit[i]+sum(i-(i&-i));
    }

    void add(int i,int x) {
        if (i>M)return;
        bit[i]+=x;
        add(i+(i&-i),x);
    }
};

int N;
int A[300005];
vector<PI> V;
int dp[300005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A[i];
        V.push_back(PI(A[i],i));
    }
    sort(V.begin(),V.end());
    BIT bit(N);
    int idx=lower_bound(V.begin(),V.end(),PI(A[0],0))-V.begin();
    int m=modPow(2,0);
    bit.add(idx+1,modPow(m,mod-2));
    for(int i=1;i<N;++i){
        idx=lower_bound(V.begin(),V.end(),PI(A[i],i))-V.begin();
        if(idx>0){
            int sum=bit.sum(idx)%mod;
            dp[i]=modPow(2,i-1);
            dp[i]*=sum;
            dp[i]%=mod;
        }
        dp[i]+=dp[i-1];
        dp[i]%=mod;
        m=modPow(2,i);
        bit.add(idx+1,modPow(m,mod-2));
    }
    cout<<dp[N-1]<<endl;
}