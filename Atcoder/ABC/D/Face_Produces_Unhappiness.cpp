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

int N,K;
string s;

int main(){
    cin>>N>>K;
    cin>>s;
    int ans=0;
    for(int i=0;i<N;++i){
        if(i!=0){
            if(s[i]=='L'&&s[i-1]=='L')ans++;
        }
        if(i!=N-1){
            if(s[i]=='R'&&s[i+1]=='R')ans++;
        }
    }
    ans=min(ans+2*K,N-1);
    cout<<min(ans,N-1)<<endl;
}