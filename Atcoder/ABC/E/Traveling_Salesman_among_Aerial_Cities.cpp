#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

struct Pos {
    int x, y, z;
    Pos(int x, int y, int z) : x(x), y(y), z(z) {} 
};

int N;
vector<Pos> p;
int dp[300000][20];

void init() {
    for (int i = 0; i < 300000; ++i) for (int j = 0; j < 20; ++j) dp[i][j] = INF;
}

signed main(){
    init();
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        p.push_back(Pos(x, y, z));
    }
    p.push_back(p[0]);
    int mbit = 1 << (N + 1) ;
    dp[1][0] = 0;
    for (int bit = 1; bit < mbit; ++bit) {
        for (int i = 0; i < N; ++i) {
            if ((bit >> i) & 1) {
                for (int j = 1; j <= N; ++j) {
                    if ((bit >> j) & 1) continue;
                    int dist = abs(p[j].x - p[i].x) + abs(p[j].y - p[i].y) + max(0ll, p[j].z - p[i].z);
                    chmin(dp[bit + (1 << j)][j], dp[bit][i] + dist);
                }
            }
        }
    }
    cout << dp[mbit - 1][N] << endl;
}