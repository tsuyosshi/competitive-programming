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

string S;
int T[200005];
int Q;

bool reversed=false;
deque<char> deq;
string ans;

signed main(){
    cin>>S;
    cin>>Q;
    for(auto s:S)deq.push_back(s);
    for(int i=0;i<Q;++i){
        cin>>T[i];
        if(T[i]==1)reversed=!reversed;
        if(T[i]==2){
            int F;
            char C;
            cin>>F>>C;
            if(!reversed){
                if(F==1)deq.push_front(C);
                else deq.push_back(C);
            }
            else {
                if(F==1)deq.push_back(C);
                else deq.push_front(C);
            }
        }
    }
    while(deq.size()){
        ans+=deq.front();
        deq.pop_front();
    }
    if(reversed)reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
