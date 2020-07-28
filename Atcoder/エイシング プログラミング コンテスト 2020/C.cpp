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
bool issq[1000005];
int ans;

bool check(int x,int y,int n){
    int d=(x+y)*(x+y)-4*(x*x+y*y+x*y-n);
    if(d<0)return false;
    if(!issq[d])return false;
    int s=-(x+y)+sqrt(d);
    if(s%2!=0)return false;
    int z=s/2;
    if(z>=1)return true;
    else return false;
}

signed main(){
    cin>>N;
    for(int i=0;i<=1000;++i)issq[i*i]=true;
    for(int i=1;i<=N;++i){
        int res=0;
        for(int x=1;x<=100;++x){
            for(int y=1;y<=100;++y){
                if(check(x,y,i))res++;
            }
        }
        cout<<res<<endl;
    }
}