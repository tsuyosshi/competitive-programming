#include<bits/stdc++.h>

using namespace std;
 
#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
 
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};
 
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N,M;
vector<int> v;
map<int,vector<int>> mp;
set<int> st;

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int x,y;
        cin>>x>>y;
        v.push_back(x);
        mp[x].push_back(y);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    st.insert(N);
    for(int i=0;i<v.size();++i){
        vector<int> p;
        vector<int> q;
        for(auto y:mp[v[i]]){
            if(st.find(y-1)!=st.end()){
                p.push_back(y);
            }
            if(st.find(y+1)!=st.end()){
                p.push_back(y);
            }
            if(st.find(y)!=st.end()){
                q.push_back(y);
            }
        }
        for(auto u:q)st.erase(u);
        for(auto u:p)st.insert(u);
    }
    cout<<st.size()<<endl;
}