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
ll mod = 1e9+7;

ll N;
ll A[300005];
ll B[300005][65][2];
ll d[61];
// B[n][k][l],n番目までにk桁目にlをもつ数の総和

ll Pow(ll x,ll n){
    ll res=1;
    for(int i=0;i<n;++i)res*=x;
    return res;
}

int main(){
    for(int i=0;i<61;++i)d[i]=Pow(2,i);
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i){
        //cout<<"i="<<i<<endl;
        for(int k=0;k<61;++k){
            int b=((A[i]&d[k])==d[k]);
            B[i][k][b]++;
            //cout<<"k="<<k<<" b="<<b<<endl;
            if(i!=0){
                B[i][k][0]+=B[i-1][k][0];
                B[i][k][1]+=B[i-1][k][1];
                B[i][k][0]%=mod;
                B[i][k][1]%=mod;
            }
            //cout<<"cnt="<<B[i][k][b]<<endl;
        }
    }
    ll ans=0;
    for(int i=0;i<N-1;++i){
        //cout<<"i="<<i<<endl;
        for(int k=0;k<60;++k){
            int b=((A[i]&d[k])==d[k]);
            //cout<<"k="<<k<<" b="<<b<<endl;
            //cout<<"cnt="<<(B[N-1][k][!b]-B[i][k][!b])<<endl;
            ans+=d[k]*(B[N-1][k][!b]-B[i][k][!b]);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}