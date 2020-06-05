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
#include <strings.h>

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

int N;
int M,C,K;
vector<int> v[25];

int dp[25][250];
//dp[服][費用]

int main(){
    cin>>N;
    while(N--){
        cin>>M>>C;
        int ans=-1;
        for(int i=0;i<C;++i){
            cin>>K;
            for(int j=0;j<K;++j){
                int a;
                cin>>a;
                v[i].push_back(a);
            }
        }
        dp[0][0]=1;
        for(int i=0;i<C;++i){
            for(int j=0;j<=M;++j){
                if(dp[i][j]!=1)continue;
                for(auto u:v[i]){
                    if(j+u<=M)dp[i+1][j+u]=1;
                }
            }
        }
        for(int i=0;i<=M;++i){
            if(dp[C][i]==1)ans=i;
        }
        if(ans==-1)cout<<"no solution"<<endl;
        else cout<<ans<<endl;
        for(int i=0;i<25;++i)for(int j=0;j<250;++j)dp[i][j]=0;
        for(int i=0;i<25;++i)v[i].clear();
    }
}