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

int A,B,C,D;

int main(){
    cin>>A>>B>>C>>D;
    int a=(A/D);
    int b=(C/B);
    if(A%D!=0)a++;
    if(C%B!=0)b++;
    if(a>=b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
