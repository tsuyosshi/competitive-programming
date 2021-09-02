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
int ans;

int dig(int x) {
    int d = 0;
    while (x != 0) {
        x /= 10;
        d++;
    }
    return d;
}

int ipow(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) res *= x;
    return res;
}

signed main(){
    cin >> N;
    int n = sqrt(N) + 1;
    for (int x = 1; x <= n; ++x) {
        int d = dig(x);
        if (x + x * ipow(10, d) > N) continue;
        ans++;
    }
    cout << ans << endl;
}