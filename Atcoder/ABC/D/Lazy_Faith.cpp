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

const ll INF=1e17;

ll A,B;
ll Q;
ll s[100005],t[100005];

ll dist(ll a,ll b,ll x){
    int d;
    if(a<=x&&b<=x)return abs(x-min(a,b));
    if(a>=x&&b>=x)return abs(x-max(a,b));
    else return min(abs(x-a),abs(x-b))+abs(a-b);
}

int main(){
    cin>>A>>B>>Q;
    for(int i=0;i<A;++i)cin>>s[i];
    for(int i=0;i<B;++i)cin>>t[i];
    sort(s,s+A);
    sort(t,t+B);
    for(int i=0;i<Q;++i){
        ll ans=INF;
        ll x;
        cin>>x;
        int shrine1=lower_bound(s,s+A,x)-s;
        int shrine2=upper_bound(s,s+A,x)-s;
        int temple1=lower_bound(t,t+B,x)-t;
        int temple2=upper_bound(t,t+B,x)-t;
        if(s[shrine1]!=x)shrine1--;
        if(t[temple1]!=x)temple1--;
        ll a=s[shrine1],b=s[shrine2],c=t[temple1],d=t[temple2];
        if(shrine1<0)a=INF;
        if(temple1<0)c=INF;
        if(shrine2==A)b=INF;
        if(temple2==B)d=INF;
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        ans=min(dist(a,c,x),min(dist(a,d,x),min(dist(b,c,x),dist(b,d,x))));
        cout<<ans<<endl;
    }
}