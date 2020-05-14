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

using namespace std;

typedef long long int ll;
const int INF =INT32_MAX;


int N,K;
int h[100005];

int dp[100005];

int main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>h[i];
    for(int i=0;i<N;++i)dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<N;++i){
        for(int j=1;j<=K;++j){
            dp[i+j]=min(dp[i]+abs(h[i+j]-h[i]),dp[i+j]);
        }
    }
    cout<<dp[N-1]<<endl;
}