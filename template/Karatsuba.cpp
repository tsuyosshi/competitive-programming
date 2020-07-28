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

//f(x)・g(x)を求める
//f(x)=x^3+2x^2-4x+3, g(x)=x^3-2x^2+2x+1
//f1(x)=x+2, f0(x)=-4x+3
//g1(x)=x-2, g0(x)=2x+1
//a(x)=x^2-4, b(x)=-8x^2+2x+3, c(x)=5x^2+14x-3
//f(x)*g(x)=x^6-6x^4+16x^3-12x^2+2x+3
//(x^2-4)x^4+(-2x^2+16x-4)x^2-8x^2+2x+3
signed main(){
}