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

const int mod = 1000000007;

int N,K;
vector<int> v[100005];
bool visited[100005];


int bfs(int s){
    int ret=K;
    queue<int> que;
    que.push(s);
    while(que.size()){
        int c=que.front();
        que.pop();
        visited[c]=true;
        for(int i=0,j=0;i<v[c].size();++i){
            if(visited[v[c][i]])continue;
            if(c==s)ret*=(K-j-1);
            else ret*=(K-j-2);
            ret%=mod;
            que.push(v[c][i]);
            j++;
        }
    }
    return ret;
}

signed main(){
    cin>>N>>K;
    for(int i=0;i<N-1;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<bfs(0)<<endl;
}
