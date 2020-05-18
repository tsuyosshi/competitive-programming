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
string S;

int seq1[100005];
vector<int> v1;
int ans;

int main(){
    cin>>N>>K;
    cin>>S;
    int t=0;
    v1.push_back(0);
    for(int i=1;i<N;++i){
        if(S[i]=='1')if(S[i+1]=='0')v1.push_back(i);
    }
    for(int i=0;i<N;++i){
        if(S[i]=='1'){
            if(i==0)seq1[i]=1;
            else seq1[i]=seq1[i-1]+1;
        }
    }
    v1.push_back(N-1);
    for(int i=0;i<v1.size();++i){
        int a;
        if(S[v1[i]]=='0')a=1;
        else a=0;
        if(i+K>=v1.size())chmax(ans,v1[v1.size()-1]-v1[i]+seq1[v1[i]]+a);
        else chmax(ans,v1[i+K]-v1[i]+seq1[v1[i]]+a);
    }
    cout<<ans<<endl;
}