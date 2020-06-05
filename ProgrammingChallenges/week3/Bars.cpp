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

int t;
int dp[25][2005];
int len[20005];


int main(){
    cin>>t;
    while(t--){
        for(int i=0;i<25;++i)for(int j=0;j<2005;++j)dp[i][j]=0;
        int n,p;
        cin>>n>>p;
        bool ok=false;
        for(int i=0;i<p;++i)cin>>len[i];
        dp[0][0]=1;
        for(int i=0;i<p;++i){
            for(int j=0;j<=n;++j){
                if(dp[i][j]==1){
                    dp[i+1][j]=dp[i][j];
                    dp[i+1][j+len[i]]=dp[i][j];
                }
            }
        }
        for(int i=0;i<=p;++i)if(dp[i][n]==1)ok=true;
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}