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
#define int long long 

using namespace std;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=INT64_MAX;
static const int mod=1000000007;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;
int A[200005],B[200005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i]>>B[i];
    sort(A,A+N);
    sort(B,B+N);
    if(N%2==1){
        int mi=A[N/2],ma=B[N/2];
        cout<<ma-mi+1<<endl;
    }
    else {
        int mi=A[N/2-1]+A[N/2],ma=B[N/2-1]+B[N/2];
        cout<<ma-mi+1<<endl;
    }
}