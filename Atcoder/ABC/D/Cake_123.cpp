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

ll X,Y,Z;
ll K;
ll A[1005],B[1005],C[1005];

vector<ll> AB;
ll sub[1000005];

int main(){
    cin>>X>>Y>>Z>>K;
    for(int i=0;i<X;++i)cin>>A[i];
    for(int i=0;i<Y;++i)cin>>B[i];
    for(int i=0;i<Z;++i)cin>>C[i];
    for(int i=0;i<X;++i)for(int j=0;j<Y;++j)AB.push_back(A[i]+B[j]);
    sort(C,C+Z,greater<ll>());
    sort(AB.begin(),AB.end(),greater<ll>());
    vector<ll> ans;
    for(int i=0;i<AB.size();++i){
        for(int j=0;j<Z;++j){
            if((i+1)*(j+1)>K)continue;
            else ans.push_back(AB[i]+C[j]);
        }
    }
    sort(ans.begin(),ans.end(),greater<ll>());
    for(int i=0;i<K;++i)cout<<ans[i]<<endl;
}