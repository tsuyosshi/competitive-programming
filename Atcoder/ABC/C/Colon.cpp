#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<limits.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const double pi=3.14159265358979323846;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

double A,B,H,M;

double a,b,c,d,e;

int main(){
    cin>>A>>B>>H>>M;
    b=(double)30*H;
    c=(double)30*M/60;
    d=(double)b+c;
    e=(double)M*6;
    d=d/360*2*pi;
    e=e/360*2*pi;
    double ans=pow(A*cos(d)-B*cos(e),2)+pow(A*sin(d)-B*sin(e),2);
    printf("%.15f", sqrt(ans));

}