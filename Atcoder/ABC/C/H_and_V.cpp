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

int H,W,K;
vector<string> fd;
int mbh,mbw;

int calc(int bh,int bw){
    int ret=0;
    for(int h=0;h<H;++h){
        if((bh>>h)&1)continue;
        for(int w=0;w<W;++w){
            if((bw>>w)&1)continue;
            if(fd[h][w]=='#')ret++;
        }
    }
    return ret;
}

signed main(){
    cin>>H>>W>>K;
    for(int i=0;i<H;++i){
        string s;
        cin>>s;
        fd.push_back(s);
    }
    mbh=1<<H;
    mbw=1<<W;
    int ans=0;
    for(int i=0;i<mbh;++i){
        for(int j=0;j<mbw;++j){
            if(K==calc(i,j))ans++;
        }
    }
    cout<<ans<<endl;
}