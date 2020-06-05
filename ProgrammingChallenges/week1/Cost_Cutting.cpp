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

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;++i){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<"Case "<<i<<": ";
        cout<<min(max(a,b),max(min(a,b),c))<<endl;
    }
}