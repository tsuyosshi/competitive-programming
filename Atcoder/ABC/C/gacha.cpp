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
string S[200005];

int main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>S[i];
    sort(S,S+N);
    int k=1;
    for(int i=1;i<N;++i){
        if(S[i]!=S[i-1])k++;
    }
    cout<<k<<endl;
}