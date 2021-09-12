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

int Q;

signed main(){
    cin>>Q;
    deque<int> dq;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(Q--){
        int c;
        cin>>c;
        if(c==1){
            int x;
            cin>>x;
            dq.push_back(x);
        }
        else {
            if(c==2){
                if(pq.size()){
                    cout<<pq.top()<<endl;
                    pq.pop();
                }
                else {
                    cout<<dq.front()<<endl;
                    dq.pop_front();
                }
            }
            else {
                while(dq.size()){
                    int v=dq.front();
                    dq.pop_front();
                    pq.push(v);
                }
            }
        }
    }
}