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

int N,T;
vector<PI> V;

int dp[3005][6005];
int ans;

int main(){
    cin>>N>>T;
    for(int i=0;i<N;++i){
        int a,b;
        cin>>a>>b;
        V.push_back(PI(a,b));
    }
    sort(V.begin(),V.end());
    for(int i=0;i<N;++i){
        PI v=V[i];
        for(int j=0;j<T;++j){
            chmax(dp[i+1][j],dp[i][j]);
            chmax(dp[i+1][j+v.first],dp[i][j]+v.second);
            chmax(ans,dp[i+1][j]);
            chmax(ans,dp[i+1][j+v.first]);
        }
    }
    cout<<ans<<endl;
}