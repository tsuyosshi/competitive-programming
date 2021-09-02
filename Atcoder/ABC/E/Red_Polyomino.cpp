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

int N,K;
vector<string> S;
set<vector<string>> st;
int ans;

void dfs(int n){
    if(st.find(S)!=st.end())return;
    st.insert(S);
    if(n==0){
        ans++;
        return;
    }
    vector<PI> next;
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(S[y][x]!='.')continue;
            bool check=false;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||nx>=N||ny<0||ny>=N||S[ny][nx]!='r')continue;
                else {
                    check=true;
                    break;
                }
            }
            if(check)next.push_back(PI(x,y));
        }
    }
    for(auto p:next){
        int x=p.first;
        int y=p.second;
        S[y][x]='r';
        dfs(n-1);
        S[y][x]='.';
    }
}

signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        string s;
        cin>>s;
        S.push_back(s);
    }
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(S[y][x]=='.'){
                S[y][x]='r';
                dfs(K-1);
                S[y][x]='.';
            }
        }
    }
    cout<<ans<<endl;
}