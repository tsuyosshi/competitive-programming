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

ll modPow(ll a, ll n) {
  if(n==1)return a%mod;
  if (n%2==1)return(a*modPow(a,n-1))%mod;
  ll t=modPow(a,n/2);
  return (t*t)%mod;
}

ll modDiv(ll a,ll b){
  return (a%mod)*modPow(b,mod-2)%mod;
}

ll comb(ll n,ll r){
  ll res=1;
  for(ll i=n;i>=n-r+1;--i){
    res*=i;
    res%=mod;
  }
  for(ll i=r;i>=1;--i)res=modDiv(res,i);
  return res%mod;
}

ll n,a,b;

int main(){
  cin>>n>>a>>b;
  ll ans=modPow(2,n)-1;
  ans-=(comb(n,a)+comb(n,b))%mod;
  ans=(ans+mod)%mod;
  cout<<ans<<endl;
}
