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

int H,W;
int M;
vector<int> row[300005];
vector<int> col[300005];
vector<int> maxw;
int numh[300005]; 

signed main(){
    cin>>H>>W>>M;
    for(int i=0;i<M;++i){
        int h,w;
        cin>>h>>w;
        h--,w--;
        row[h].push_back(w);
        col[w].push_back(h);
    }
    for(int i=0;i<H;++i){
        if(row[i].size()==0)continue;
        sort(row[i].begin(),row[i].end());
    }
    int ma=0;
    for(int i=0;i<W;++i){
        if(col[i].size()==0)continue;
        sort(col[i].begin(),col[i].end());
        chmax(ma,(int)col[i].size());
    }
    for(int i=0;i<W;++i){
        if(ma==col[i].size())maxw.push_back(i);
    }
    for(auto i:maxw){
        for(auto u:col[i]){
            numh[u]++;
        }
    }
    int ans=0;
    for(int y=0;y<H;++y){
        if(numh[y]==maxw.size())chmax(ans,ma+(int)row[y].size()-1);
        else chmax(ans,ma+(int)row[y].size());
    }
    cout<<ans<<endl;
}