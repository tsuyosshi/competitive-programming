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

const ll INF=1e18;

ll N,K;
vector<ll> A;

int main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        int a;
        cin>>a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());


    ll r=INF,l=-INF-1;
    ll m;
    while(r-l>1){
        m=(r+l)/2ll;
        ll cnt=0;
        for(int i=0;i<N;++i){
            if(A[i]==0){
                if(m>=0)cnt+=i;
            }
            else{
                ll d;
                ll id;
                if(A[i]>0){
                    d=m/A[i];
                    if(m<=0&&m%A[i]!=0)d--;
                    cnt+=upper_bound(A.begin(),A.begin()+i,d)-A.begin();     
                }
                else{
                    d=m/A[i];
                    cnt+=A.begin()+i-lower_bound(A.begin(),A.begin()+i,d);;
                }
            }
        }
        if(cnt>=K)r=m;
        else l=m;
    }
    cout<<r<<endl;
}