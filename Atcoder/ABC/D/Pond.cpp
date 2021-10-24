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

int K,N;
vector<vector<int>> A(1000);

bool check(int X){
    vector<vector<int>> B;
    vector<vector<int>> V;
    B.assign(N,vector<int>(N,0));
    V.assign(N,vector<int>(N,0));
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(A[y][x]>X)B[y][x]=1;
        }
    }
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            V[y][x]+=B[y][x];
            if(x!=0&&y!=0)V[y][x]+=V[y-1][x]+V[y][x-1]-V[y-1][x-1];
            else if(x!=0)V[y][x]+=V[y][x-1];
            else if(y!=0)V[y][x]+=V[y-1][x];
        }
    }
    bool ok=false;
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(x+K-1>=N||y+K-1>=N)continue;
            int cnt=V[y+K-1][x+K-1];
            if(x!=0&&y!=0)cnt-=V[y+K-1][x-1]+V[y-1][x+K-1]-V[y-1][x-1];
            else if(x!=0)cnt-=V[y+K-1][x-1];
            else if(y!=0)cnt-=V[y-1][x+K-1];
            if(cnt<K*K/2+1)ok=true;
        }
    }
    return ok;
}

signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            int a;
            cin>>a;
            A[i].push_back(a);
        }
    }
    int l=0,r=10000000000;
    int X;
    while(r-l>1){
        X=(l+r)/2;
        bool ok=check(X);
        if(ok){
            r=X;
        }
        else l=X;
    }
    if(check(l))cout<<l<<endl;
    else cout<<r<<endl;
}
