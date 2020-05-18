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

int N,M;

vector<int> G[100005];
int flag[100005];
PI ans[100005];


int main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        if(flag[v]==1)continue;
        flag[v]=1;
        PI res=PI(IINF,IINF);
        for(int i=0;i<G[v].size();++i){
            int nv=G[v][i];
            //cout<<nv<<endl;
            if(v==0)que.push(nv);
            else if(flag[nv]==1)chmin(res,PI(ans[nv].first+1,nv));
            else que.push(nv);
        }
        if(v==0)ans[v]=PI(0,0);
        else ans[v]=res;
        //cout<<ans[v].first<<" "<<ans[v].second<<endl;
    }
    for(int i=0;i<N;++i){
        if(ans[i].first==IINF){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<N;++i)cout<<ans[i].second+1<<endl;
}