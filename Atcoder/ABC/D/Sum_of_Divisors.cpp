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

template<typename T>
vector<T> smallest_prime_factors(T n) {
    vector<T> spf(n+1);
    for (int i=0;i<=n;i++)spf[i]=i;
    for (T i=2;i*i<=n;i++){

        // 素数だったら
        if (spf[i]==i){
            for (T j=i*i;j<=n;j+=i){
                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j]==j) {
                    spf[j]=i;
                }
            }
        }
    }
    return spf;
}

template<typename T>
vector<T> factolization(T x, vector<T> &spf) {
    vector<T> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    sort(ret.begin(), ret.end());
    return ret;
}

const int MAX_N=10000000;
int N;
int ans;

signed main(){
    auto spf = smallest_prime_factors(MAX_N);
    cin>>N;
    for(int i=2;i<=N;++i){
        auto res=factolization(i,spf);
        int sum=1;
        int t=1;
        for(int j=1;j<res.size();++j){
            if(res[j]==res[j-1])t++;
            else {
                sum*=(t+1);
                t=1;
            }
        }
        sum*=(t+1);
        ans+=i*sum;
    }
    cout<<ans+1<<endl;
    return 0;
}