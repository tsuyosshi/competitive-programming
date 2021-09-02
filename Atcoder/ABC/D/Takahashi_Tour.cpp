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

int N;
priority_queue<int,vector<int>,greater<int>> que[200005];
int pre[200005];
bool visited[200005];
vector<int> ans;

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        pre[i]=-1;
        visited[i]=false;
    }
    for(int i=0;i<N-1;++i){
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        que[A].push(B);
        que[B].push(A);
    }
    int city=0;
    while(true){
        ans.push_back(city);
        visited[city]=true;
        int next=-1;
        if(que[city].size()){
            while(que[city].size()){
                next=que[city].top();
                que[city].pop();
                if(next!=-1&&!visited[next])break;
            }
            if(next!=-1&&pre[next]==-1)pre[next]=city;
        }
        if(next==-1){
            if(city==0)break;
            else next=pre[city];
        }
        city=next;
    }
    for(auto city:ans)cout<<city+1<<" ";
    cout<<endl;
}