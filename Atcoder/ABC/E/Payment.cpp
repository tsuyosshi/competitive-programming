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
typedef pair<ll,ll> PL;
typedef pair<ll,pair<ll,ll>> PLL;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const double eps=1e-13;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

string N;

int main(){
    cin>>N;
    reverse(N.begin(),N.end());
    N+='0';
    int ans=0;
    int c=0;
    for(int i=0;i<N.size()-1;++i){
        int n=N[i]-'0';
        if(n+c<=4){
            ans+=n+c;
            c=0;
        }
        else if(n+c==5){
            if(N[i+1]-'0'<=4){
                ans+=n+c;
                c=0;
            }
            else {
                ans+=10-(n+c);
                c=1;
            }
        }
        else if(n+c>5){
            ans+=10-(n+c);
            c=1;
        }
    }
    ans+=c;
    cout<<ans<<endl;
}