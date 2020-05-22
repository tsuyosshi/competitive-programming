#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<limits.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int MAX_N=1000;

int N;
int A[MAX_N+5][MAX_N+5];

int id[MAX_N+5][MAX_N+5];
int t;

vector<int> G[MAX_N*MAX_N];
bool isVisited[MAX_N*MAX_N];
bool isCalculated[MAX_N*MAX_N];
int d[MAX_N*MAX_N];

void setId(int i,int j){
    if(i>j)swap(i,j);
    if(id[i][j]==-1)id[i][j]=t++;
}

int getId(int i, int j){
    if(i>j)swap(i,j);
    return id[i][j];
}


int dfs(int v){
    if(isVisited[v]){
        if(!isCalculated[v])return -1;
        return d[v];
    }
    isVisited[v]=true;
    d[v]=1;
    for(auto u:G[v]){
        int res=dfs(u);
        if(res==-1)return -1;
        chmax(d[v],res+1);
    }
    isCalculated[v]=true;
    return d[v];
}

int main(){
    cin>>N;
    for(int i=0;i<MAX_N;++i)for(int j=0;j<MAX_N;++j)id[i][j]=-1;
    for(int i=0;i<N;++i){
        for(int j=0;j<N-1;++j){
            cin>>A[i][j];
            A[i][j]--;
            setId(i,A[i][j]);
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N-2;++j){
            G[getId(i,A[i][j])].push_back(getId(i,A[i][j+1]));
        }
    }
    int ans=0;
    for(int i=0;i<t;++i){
        int res=dfs(i);
        if(res==-1){
            cout<<-1<<endl;
            return 0;
        }
        chmax(ans,res);
    }
    cout<<ans<<endl;
}