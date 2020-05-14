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

string S;

int m[2020];

int modPow(int a, int n) {
  if(n==1)return a % 2019;
  if (n%2==1)return(a*modPow(a,n-1))%2019;
  int t=modPow(a,n/2);
  return (t*t)%2019;
}

int main(){
    cin>>S;
    reverse(S.begin(),S.end());
    int mod=S[0]-'0';
    m[0]++;
    m[mod]++;
    int Xi;
    int ans=0;
    for(int i=1;i<S.size();++i){
        int s=S[i]-'0';
        Xi=(mod+s*modPow(10,i))%2019;
        ans+=m[Xi];
        m[Xi]++;
        mod=Xi;
    }
    cout<<ans<<endl;
}