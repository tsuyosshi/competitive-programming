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
double X0, Y0, XN, YN;

signed main(){
    cin >> N;
    cin >> X0 >> Y0 >> XN >> YN;
    double CX = (XN + X0) / 2.0, CY = (YN + Y0) / 2.0;
    double rad = (double)(2.0 * pi / N);
    double X = (X0 - CX) * cos(rad) - (Y0 - CY) * sin(rad), Y = (X0 - CX) * sin(rad) + (Y0 - CY) * cos(rad);
    printf("%.20f %.20f\n", CX + X, CY + Y);
}