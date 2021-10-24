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

string N;
int ans=-INF;

signed main(){
    cin>>N;
    for(int i=0;i<(1<<N.size());++i){
        string a="",b="";
        for(int j=0;j<N.size();++j){
            if((i>>j)&1)a+=N[j];
            else b+=N[j];
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        if(a.size()==0||b.size()==0)continue;
        int A=stoi(a);
        int B=stoi(b);
        chmax(ans,A*B);
    }
    cout<<ans<<endl;
}