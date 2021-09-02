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

signed main(){
    int Q;
    cin>>Q;
    priority_queue<int,vector<int>,greater<int>> que;
    int A=0;
    while(Q--){
        int P;
        cin>>P;
        if(P!=3){
            int X;
            cin>>X;
            if(P==1)que.push(X-A);
            else A+=X;
        }
        else {
            cout<<que.top()+A<<endl;
            que.pop();
        }
    }
}