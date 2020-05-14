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

string S,T;

int main(){
    cin>>S>>T;
    for(int i=0;i<27;++i){
        if(S+(char)(i+'a')==T){
            return 0;
            cout<<"Yes"<<endl;
        }
    }
    cout<<"No"<<endl;
}