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
static const double eps=1e-13;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;
ll A[100005];

ll res=1;

ll maxR=1e18+0.5;

bool ok=true;


int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A[i];
        if(A[i]==0)ok=false;
    }
    if(!ok){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<N;++i){
        ll c=maxR/res;
        if(A[i]>c){
            cout<<-1<<endl;
            return 0;
        }
        res*=A[i];
    }
    cout<<res<<endl;
}
