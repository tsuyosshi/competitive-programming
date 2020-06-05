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
#define int long long 

using namespace std;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=INT64_MAX;
static const int mod=1000000007;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int MAX_N=100;

int T;

vector<int> G[MAX_N+5];
bool isvisited[MAX_N+5];
bool isreached=false;
bool isreachable=false;

string ans;

void dfs1(int n,int e){
    if(isreachable)return;
    if(n==e){
        isreachable=true;
        return;
    }
    if(isvisited[n])return;
    isvisited[n]=true;
    for(auto u:G[n]){
        dfs1(u,e);
    }
}

void dfs2(int n,int e,int dom){
    if(isreached)return;
    if(n==dom)return;
    if(n==e){
        isreached=true;
        return;
    }
    if(isvisited[n])return;
    isvisited[n]=true;
    for(auto u:G[n]){
        dfs2(u,e,dom);
    }
}

signed main(){
    cin>>T;
    int C=T;
    while(T--){
        int N;
        cin>>N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                int a;
                cin>>a;
                if(a==1)G[i].push_back(j);
            }
        }
        cout<<"Case "<<C-T<<":"<<endl;
        for(int i=0;i<N;++i){
            ans="|";
            for(int j=0;j<N;++j){
                for(int k=0;k<MAX_N;++k)isvisited[k]=false;
                isreachable=false;
                dfs1(0,j);
                for(int k=0;k<MAX_N;++k)isvisited[k]=false;
                isreached=false;
                dfs2(0,j,i);
                if(!isreachable||isreached)ans+="N";
                else ans+="Y";
                ans+="|";
            }
            cout<<"+";
            for(int j=0;j<ans.size()-2;++j)cout<<"-";
            cout<<"+"<<endl;
            cout<<ans<<endl;
            if(i==N-1){
                cout<<"+";
                for(int j=0;j<ans.size()-2;++j)cout<<"-";
                cout<<"+"<<endl;
            }
            ans.clear();
        }
        for(int i=0;i<MAX_N;++i)G[i].clear();
    }
}