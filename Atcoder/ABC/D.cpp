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

ll N;
ll A[200005];
ll K;

bool flag[200005];
ll hs;
ll t=0;

void search(int n){
    if(flag[n]!=0){
        hs=n;
        return;
    }
    if(t==K){
        cout<<n<<endl;
        hs=-1;
        return;
    }
    flag[n]=true;
    t++;
    search(A[n]);
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>A[i];
        A[i]--;
    }
    search(0);
    if(hs==-1)return 0;
    ll k=0;
    ll p=hs;
    while(true){
        p=A[p];
        k++;
        if(p==hs)break;
    }
    ll q=(K-(t-k))%k;
    ll ans=hs;
    for(int i=0;i<q;++i)ans=A[ans];
    cout<<ans+1<<endl;
}