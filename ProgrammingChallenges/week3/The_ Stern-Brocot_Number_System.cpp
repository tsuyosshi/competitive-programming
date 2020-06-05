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
#include <strings.h>

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

void search(double t){
    double l1=0,l2=1,r1=1,r2=0;
    double mid1,mid2;
    while(true){
        mid1=l1+r1,mid2=l2+r2;
        if(abs(t-mid1/mid2)<eps)break;
        if(t<mid1/mid2){
            r1=mid1,r2=mid2;
            cout<<"L";
        }
        else {
            l1=mid1,l2=mid2;
            cout<<"R";
        }
    }
    cout<<endl;
}

int main(){
    while(true){
        double a,b;
        cin>>a>>b;
        if(a==1.0&&b==1.0)break;
        search(a/b);
    }
}
