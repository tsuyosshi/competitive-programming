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
const int INF =1e11;


int N;
int h[100005];

int dp[100005];

int main(){
    cout<<INF<<endl;
    cin>>N;
    for(int i=0;i<N;++i)cin>>h[i];
    for(int i=0;i<N;++i)dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<N;++i){
        dp[i+1]=min(dp[i]+abs(h[i+1]-h[i]),dp[i+1]);
        dp[i+2]=min(dp[i]+abs(h[i+2]-h[i]),dp[i+2]);
    }
    cout<<dp[N-1]<<endl;
}