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

const ll MAX_N=1e5;
const ll MAX_M=1e9;

ll N,M;
ll a[MAX_N+5];

bool ok=true;

ll gcd(ll a,ll b){
    if(a%b!=0)return gcd(b,a%b);
    else return b;
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

ll count(ll x){
    ll res=0;
    while(x%2==0){
        x/=2;
        res++;
    }
    return res;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>a[i];
        ll x=a[i]/2;
        if(i!=0&&count(a[i])!=count(a[i-1]))ok=false;
    }
    if(!ok){
        cout<<0<<endl;
        return 0;
    }
    ll X=a[0]/2;
    for(int i=1;i<N;++i){
        X=lcm(X,a[i]/2);
        if(X>M){
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans=0;
    for(ll i=1;i<=M;++i){
        if(X*(2*i-1)>M)break;
        ans++;
    }
    cout<<ans<<endl;
}