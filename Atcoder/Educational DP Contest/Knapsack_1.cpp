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

int N,W;
ll w[100005],v[100005];

ll dp[105][100005];
ll ans;

int main(){
    cin>>N>>W;
    for(int i=0;i<N;++i)cin>>w[i]>>v[i];
    for(int i=0;i<N;++i){
        for(int j=0;j<=W;++j){
            if(j<w[i])dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    cout<<dp[N][W]<<endl;
}