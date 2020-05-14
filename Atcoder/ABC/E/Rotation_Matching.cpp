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
#include<limits.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

int N,M;

int main(){
    cin>>N>>M;
    if(N%2==1){
        for(int i=1;i<=M;++i){
            cout<<i<<" "<<N-i+1<<endl;
        }
    }
    else{
        for(int i=1;i<=M;++i){
            if(N-2*i+1>2*i-1)cout<<i<<" "<<N-i+1<<endl;
            else cout<<i<<" "<<N-i<<endl;
        }
    }
}