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
int X, Y;
char s[110][110];
int ans;

signed main(){
    cin >> H >> W >> X >> Y;
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> s[j][i];  
    for (int i = 0; i < 4; ++i) {
        int x = X - 1, y = Y - 1;
        while(true) {
            x += dx[i], y += dy[i];
            if (x < 0 || x >= H || y < 0 || y >= W) break;
            if (s[y][x] != '#') ans++;
            else break;
        }
    }
    if (s[Y - 1][X - 1] != '#') ans++;
    cout << ans << endl;
}