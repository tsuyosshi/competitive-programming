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

int H, W;
int A, B;
vector<vector<int>> tile;
int ans;

void dfs(int x, int y, vector<vector<int>>& t, int a) {
    if (x < 0 || x >= W || y < 0 || y >= H) return;
    if (x == W - 1 && y == H - 1) {
        if (a == A) ans++;
        return; 
    }
    // 横にしく
    if (x < W - 1 && t[y][x] == 0 && t[y][x + 1] == 0) {
        t[y][x] = 1, t[y][x + 1] = 1;
        dfs(x + 1, y, t, a + 1);
        t[y][x] = 0, t[y][x + 1] = 0;
    }
    // 縦にしく
    if (y < H - 1 && t[y][x] == 0 && t[y + 1][x] == 0) {
        t[y][x] = 1, t[y + 1][x] = 1;
        if (x == W - 1) dfs(0, y + 1, t, a + 1);
        else dfs(x + 1, y, t, a + 1);
        t[y][x] = 0, t[y + 1][x] = 0;
    }
    if (x == W - 1) dfs(0, y + 1, t, a);
    else dfs(x + 1, y, t, a);
}


signed main(){
    cin >> H >> W;
    cin >> A >> B;
    for(int y = 0; y < H; ++y) {
        vector<int> tmp;
        for (int x = 0; x < W; ++x) tmp.push_back(0);
        tile.push_back(tmp);
    }
    dfs(0, 0, tile, 0);
    cout << ans << endl;
}