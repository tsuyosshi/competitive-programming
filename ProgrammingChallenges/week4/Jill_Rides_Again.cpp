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

int b;

int route;
int d[20005];

struct D{
    int value;
    int l,r;
    int segment;
    void update(int _value,int _l,int _r){
        value=_value;
        l=_l;
        r=_r;
        segment=r-l;
    }
};

D dp[20005];

int main(){
    cin>>b;
    while(b--){
        int s;
        cin>>s;
        for(int i=0;i<s-1;++i)cin>>d[i];
        for(int i=0;i<20005;++i)dp[i].update(-1e5,0,0);
        for(int i=0;i<s-1;++i){
            if(dp[i+1].value<d[i])dp[i+1].update(d[i],i,i+1);
            if(dp[i+1].value<dp[i].value+d[i])dp[i+1].update(dp[i].value+d[i],dp[i].l,i+1);
            if(dp[i+1].value==dp[i].value+d[i])if(dp[i+1].segment<i+1-dp[i].l)dp[i+1].update(dp[i].value+d[i],dp[i].l,i+1);
        }
        D ans;
        ans.update(-1e5,0,0);
        for(int i=0;i<s;++i){
            if(ans.value<dp[i].value)ans=dp[i];
            else if(ans.value==dp[i].value){
                if(ans.segment<dp[i].segment)ans=dp[i];
            }
        }
        if(ans.value<0)cout<<"Route "<<route+1<<" has no nice parts"<<endl;
        else cout<<"The nicest part of route "<<route+1<<" is between stops "<<ans.l+1<<" and "<<ans.r+1<<endl;
        route++;
    }
}