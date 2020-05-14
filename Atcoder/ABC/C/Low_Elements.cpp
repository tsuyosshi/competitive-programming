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

int N;
int P[200005];
int ans;

int main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>P[i];
    int mi=2000005;
    for(int i=1;i<N;++i){
        if(mi>=P[i])ans++;
        mi=min(mi,P[i]);
    }
    cout<<ans+1<<endl;
}