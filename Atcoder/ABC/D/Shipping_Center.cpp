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

int N,M;
int Q;
int W[55],V[55];
int X[55];

signed main(){
    cin>>N>>M>>Q;
    for(int i=0;i<N;++i)cin>>W[i]>>V[i];
    for(int i=0;i<M;++i)cin>>X[i];
    while(Q--){
        int l,r;
        int ans=0;
        bool used[55]={false};
        cin>>l>>r;
        l--,r--;
        vector<int> x;
        for(int i=0;i<M;++i){
            if(i>=l&&i<=r)continue;
            x.push_back(X[i]);
        }
        sort(x.begin(),x.end());
        for(int i=0;i<x.size();++i){
            int ma=-INF,ma_id=-1;
            for(int j=0;j<N;++j){
                if(used[j])continue;
                if(x[i]>=W[j]&&ma<V[j]){
                    ma=V[j];
                    ma_id=j;
                }
            }
            if(ma_id!=-1){
                ans+=ma;
                used[ma_id]=true;
            }
        }
        cout<<ans<<endl;
    }
}