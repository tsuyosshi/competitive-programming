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
int X,Y;

int a[20005];

int main(){
    cin>>N>>X>>Y;
    for(int i=1;i<=N-1;++i){
        for(int j=i+1;j<=N;++j){
            int dist=min(j-i,abs(X-i)+1+abs(Y-j));
            a[dist]++;
        }
    }
    for(int k=1;k<N;++k)cout<<a[k]<<endl;
}