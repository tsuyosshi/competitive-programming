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
#include <strings.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const double eps=1e-13;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;

double ax,ay,az;
bool ok;

void update(double x,double y,double z){
    if(x==y||x==z||y==z)return;
    ok=true;
    if(ax>x)ax=x,ay=y,az=z;
    else if(ax==x){
        if(ay>y)ax=x,ay=y,az=z;
        else if(ay==y){
            if(az>z)ax=x,ay=y,az=z;
        }
    }
}

bool check(double x,double y,double z,double r){
    double R=x*x+y*y+z*z;
    return (abs(R-r)<eps);
}

double discriminant(double a,double b,double c){
    return b*b-4*a*c;
}

int main(){
    cin>>N;
    while(N--){
        double A,B,C;
        cin>>A>>B>>C;
        ax=10001,ay=10001,az=10001;
        ok=false;
        for(double x=-10000;x<=10000;++x){
            if(x==0)continue;
            double d=discriminant(1.0,A-x,B/x);
            if(d<0)continue;
            double y1=((A-x)+sqrt(d))/2;
            double y2=((A-x)-sqrt(d))/2;
            double z1=A-x-y1;
            double z2=A-x-y2;
            if(check(x,y1,z1,C))update(x,y1,z1);
            if(check(x,y2,z2,C))update(x,y2,z2);
        }
        if(ok)cout<<ax<<" "<<ay<<" "<<az<<endl;
        else cout<<"No solution."<<endl;
    }
}