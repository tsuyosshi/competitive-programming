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

ll fact[200005];
ll fact_inv[200005];

class Comb{
public:
    Comb(ll N){
        fact[0]=1;
        fact_inv[0]=1;
        for(int i=1;i<=N;++i){
            fact[i]=fact[i-1]*i%mod;
            fact_inv[i]=modPow(fact[i],mod-2);
        }
    }

    ll modPow(ll a, ll n) {
        if(n==1)return a%mod;
        if (n%2==1)return(a*modPow(a,n-1))%mod;
        ll t=modPow(a,n/2);
        return (t*t)%mod;
    }

    ll comb(ll n,ll r){
        return (((fact[n]*fact_inv[r])%mod)*fact_inv[n-r])%mod;
    }
};

int main(){
}