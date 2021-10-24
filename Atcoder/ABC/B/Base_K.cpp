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

int K;
string A,B;

int _pow(int x,int n){
    int res=1;
    for(int i=0;i<n;++i)res*=x;
    return res;
}

signed main(){
    cin>>K;
    cin>>A>>B;
    int a=0,b=0;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i=0;i<A.size();++i)a+=(A[i]-'0')*_pow(K,i);
    for(int i=0;i<B.size();++i)b+=(B[i]-'0')*_pow(K,i);
    cout<<a*b<<endl;
}