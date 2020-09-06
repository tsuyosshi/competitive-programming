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

const int MAX_N=500;
const int MAX_A=100000;

int N,K;
int A[MAX_N+5];

int sum;
int ans;

vector<int> divisor(int n) {
    vector<int> res;
    for (int i=1;i*i<=n;i++) {
        res.push_back(i);
        if(n%i==0)res.push_back(n/i);
    }
    sort(res.begin(),res.end());
    return res;
}

bool check(int m){
    vector<int> d;
    for(int i=0;i<N;++i)d.push_back(A[i]%m);
    sort(d.begin(),d.end());
    int l=0,r=N-1;
    int cnt=0;
    while(true){
        if(r==l){
            if(d[l]%m==0)return true;
            else return false;
        }
        if(cnt>K)return false;
        if(d[l]%m==0)l++;
        else if(d[r]%m==0)r--;
        else {
            int cost=min(d[l],m-d[r]);
            cnt+=cost;
            d[l]-=cost;
            d[r]+=cost;
        }
    }
}

signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>A[i];
        sum+=A[i];
    }
    for(auto m:divisor(sum)){
        if(check(m))ans=m;
    }
    cout<<ans<<endl;
}
