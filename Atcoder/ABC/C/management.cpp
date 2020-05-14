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

int M[200005];

int main(){
    cin>>N;
    for(int i=0;i<N-1;++i){
        int a;
        cin>>a;
        a--;
        M[a]++;
    }
    for(int i=0;i<N;++i)cout<<M[i]<<endl;
}
