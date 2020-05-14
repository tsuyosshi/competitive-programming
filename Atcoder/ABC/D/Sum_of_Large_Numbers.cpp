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

const ll mod=1e9+7; 

ll N,K;
ll v[200005];

int main(){
    cin>>N>>K;
    for(int i=1;i<=N;++i)v[i]=v[i-1]+i;
    ll ans=0LL;
    for(int i=K;i<=N+1;++i){
        ll ma,mi;
        if(i==N+1)ma=v[N];
        else ma=v[N]-v[N-i];
        mi=v[i-1];
        //cout<<ma<<" "<<mi<<endl;
        ans+=(ma-mi+1)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}