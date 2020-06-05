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
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,M;
vector<int> dr,kn;

void clear(){
    dr.clear();
    kn.clear();
}

int main(){
    while(true){
        cin>>N>>M;
        if(N==0&&M==0)break;
        for(int i=0;i<N;++i){
            int d;
            cin>>d;
            dr.push_back(d);
        }
        for(int i=0;i<M;++i){
            int h;
            cin>>h;
            kn.push_back(h);
        }
        if(dr.size()>kn.size()){
            cout<<"Loowater is doomed!"<<endl;
            clear();
            continue;
        }
        sort(dr.begin(),dr.end());
        sort(kn.begin(),kn.end());
        int cost=0;
        int pid=0;
        bool ok=true;
        for(auto d:dr){
            int id=lower_bound(kn.begin()+pid,kn.end(),d)-kn.begin();
            if(id==kn.size()){
                cout<<"Loowater is doomed!"<<endl;
                ok=false;
                clear();
                break;
            }
            else{
                cost+=kn[id];
                pid=id+1;
            }
        }
        if(ok)cout<<cost<<endl;
        clear();
    }
}