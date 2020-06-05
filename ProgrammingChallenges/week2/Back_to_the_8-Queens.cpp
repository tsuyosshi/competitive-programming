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

int v[10];
int ans;

vector<int> p;

void dfs(int n,int res){
    if(n==9){
        chmin(ans,res);
        return;
    }
    for(int i=1;i<=8;++i){
        bool ok=true;
        for(int j=0;j<p.size();++j){
            if(i==p[j]){
                ok=false;
                break;
            }
            if(abs(i-p[j])==n-j-1){
                ok=false;
                break;
            }
        }
        if(ok){
            p.push_back(i);
            if(v[n]==i)dfs(n+1,res);
            else dfs(n+1,res+1);
            p.pop_back();
        }
    }
}

int main(){
    int t=0;
    int c=0;
    while(cin>>v[t+1]){
        t++;
        t%=8;
        if(t==0){
            c++;
            ans=IINF;
            for(int i=1;i<=8;++i){
                p.push_back(i);
                if(v[1]==i)dfs(2,0);
                else dfs(2,1);
                p.pop_back();
            }
            cout<<"Case "<<c<<": ";
            cout<<ans<<endl;
        }
    }
}

