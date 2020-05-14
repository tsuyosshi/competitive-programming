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

int N;
int v[100005][3];

int dp[100005][3];
int ans;

int main(){
    cin>>N;
    for(int i=0;i<N;++i)for(int j=0;j<3;++j)cin>>v[i][j];
    for(int i=0;i<3;++i)dp[0][i]=v[0][i];
    for(int i=0;i<N;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                if(j==k)continue;
                chmax(dp[i+1][k],dp[i][j]+v[i+1][k]);
            }    
        }
    }
    for(int i=0;i<3;++i)chmax(ans,dp[N-1][i]);
    cout<<ans<<endl;
}