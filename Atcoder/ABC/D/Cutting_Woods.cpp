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

int L,Q;
map<int,bool> mp;

signed main(){
    cin>>L>>Q;
    while(Q--){
        int c,x;
        cin>>c>>x;
        if(c==1)mp[x]=true;
        else {
            int l=0,r=L;
            decltype(mp)::iterator itr1=mp.lower_bound(x);
            decltype(mp)::iterator itr2=mp.upper_bound(x);
            if(itr1!=mp.begin()){
                itr1--;
                l=itr1->first;
            }
            if(itr2!=mp.end()){
                r=itr2->first;
            }
            cout<<r-l<<endl;
        }
    }
}