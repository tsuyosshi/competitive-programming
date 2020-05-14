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

int N,M;
int sum;

int main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int h;
        cin>>h;
        sum+=h;
    }
    if(N-sum>0)cout<<N-sum<<endl;
    else cout<<-1<<endl;
}