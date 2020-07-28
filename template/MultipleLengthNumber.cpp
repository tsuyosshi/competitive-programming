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

/*int modPow(int a, int n, int mod) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1,mod))%mod;
    int t=modPow(a,n/2,mod);
    return (t*t)%mod;
}*/

int pow(int x, int n){
    int ret=1;
    for(int i=0;i<n;++i)ret*=x;
    return ret;
}

void div(string a, int b){
    string ret="";
    int k=a.size();
    int r0,r1=0;
    for(int i=0;i<k;++i){
        r0=a[i]-'0';
        int v=r1*pow(10,k)+r0;
        int q=v/b;
        int r=v%b;
        cout << v << endl;
        //cout << r << endl;
        //cout<<q<<endl;
        r1=r0;
        ret+=(char)(q+'0');
    }
    cout<< ret << " " << r0 << endl;
}

signed main(){
    div("20200713",7); 
}