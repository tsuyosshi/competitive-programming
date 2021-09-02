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
int X[200005];
int C[200005];
vector<int> tmp[200005];
vector<vector<int>> group;
int dp[200005][2];

void init() {
    for (int i = 0; i < 200005; ++i) for (int j = 0; j < 2; ++j) dp[i][j] = INF;
}

signed main(){
    init();
    cin >> N;
    tmp[0].push_back(0);
    tmp[N + 1].push_back(0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> C[i];
        tmp[C[i]].push_back(X[i]);
    }
    for (int i = 0; i <= N + 1; ++i) if (tmp[i].size() != 0) group.push_back(tmp[i]);
    for (int i = 0; i < group.size(); ++i) sort(group[i].begin(), group[i].end());
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 0; i < group.size() - 1; ++i) {
        int n = group[i + 1].size();
        for (int j = 0; j < 2; ++j) {
            int dist1, dist2;
            int pre = (j == 0) ? 0 : group[i].size() - 1;
            dist1 = abs(group[i + 1][n - 1] - group[i][pre]) + abs(group[i + 1][n - 1] - group[i + 1][0]);
            dist2 = abs(group[i + 1][0] - group[i][pre]) + abs(group[i + 1][n - 1] - group[i + 1][0]);
            chmin(dp[i + 1][0], dp[i][j] + dist1);
            chmin(dp[i + 1][1], dp[i][j] + dist2);
        }
    }
    cout << min(dp[group.size() - 1][0], dp[group.size() - 1][1]) << endl;
}