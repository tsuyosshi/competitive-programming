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
typedef long long ll;

int calc(int n){
    int n_=n;
    int len=1;
    while(n_>1){
        if(n_%2==1)n_=3*n_+1;
        else n_=n_/2;
        len++;
    }
    return len;
}


int main(){
    int I,J;
    while(cin>>I>>J){
        cout<<I<<" "<<J<<" ";
        int ans=0;
        for(int n=min(I,J);n<=max(I,J);++n)ans=max(ans,calc(n));
        cout<<ans<<endl;
    }
}