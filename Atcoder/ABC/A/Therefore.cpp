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

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

string N;

int a[5]={2,4,5,7,9},b[4]={0,1,6,8},c[1]={3};

int main(){
    cin>>N;
    for(int i=0;i<5;++i){
        if(N[N.size()-1]-'0'==a[i]){
            cout<<"hon"<<endl;
            return 0;
        }
    }
    for(int i=0;i<4;++i){
        if(N[N.size()-1]-'0'==b[i]){
            cout<<"pon"<<endl;
            return 0;
        }
    }
    for(int i=0;i<1;++i){
        if(N[N.size()-1]-'0'==c[i]){
            cout<<"bon"<<endl;
            return 0;
        }
    }

}