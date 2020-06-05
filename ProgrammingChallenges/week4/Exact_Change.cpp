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

int n;
int v[110];

PI dp[110][21000];

int main(){
    cin>>n;
    while(n--){
        for(int i=0;i<110;++i)for(int j=0;j<21000;++j)dp[i][j]=PI(0,IINF);
        int price,m;
        cin>>price>>m;
        for(int i=0;i<m;++i)cin>>v[i];
        dp[0][0]=PI(1,0);
        for(int i=0;i<m;++i){
            for(int j=0;j<=price;++j){
                if(dp[i][j].first==1){
                    if(dp[i+1][j].second>dp[i][j].second)dp[i+1][j]=dp[i][j];
                    if(dp[i+1][j+v[i]].second>dp[i][j].second+1)dp[i+1][j+v[i]]=PI(dp[i][j].first,dp[i][j].second+1);
                }
            }
        }
        PI ans=PI(IINF,IINF);
        for(int i=0;i<=m;++i){
            for(int j=price;j<=20000;++j){
                if(dp[i][j].first==1){
                    if(ans.first>j)ans=PI(j,dp[i][j].second);
                    else if(ans.first==j&&ans.second>dp[i][j].second)ans=PI(j,dp[i][j].second);
                }
            }
        }
        cout<<ans.first<<" "<<ans.second<<endl;
    }
}