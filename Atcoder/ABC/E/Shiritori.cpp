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

int N;
int N_;
vector<string> S;
vector<string> T;
map<string,vector<int>> mp;
vector<int> E[200005];
vector<int> revE[200005];
int mem[200005];
int cnt[200005];

void bfs(){
    queue<int> que;
    for(int i=0;i<N_;++i){
        if(cnt[i]==0){
            mem[i]=0;
            que.push(i);
        }
    }
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:revE[v]){
            if(mem[u]==-1){
                if(mem[v]==0){
                    mem[u]=1;
                    que.push(u);
                }
                else if(mem[v]==1)cnt[u]--;
                if(cnt[u]==0){
                    mem[u]=0;
                    que.push(u);
                }
            }
        }
    }
}

signed main(){
    for(int i=0;i<200005;++i)mem[i]=-1;
    cin>>N;
    for(int i=0;i<N;++i){
        string s;
        cin>>s;
        S.push_back(s);
        T.push_back(s);
    }
    sort(S.begin(),S.end());
    S.erase(unique(S.begin(),S.end()),S.end());
    N_=S.size();
    for(int i=0;i<N_;++i){
        string s=S[i];
        mp[s.substr(0,3)].push_back(i);
    }
    for(int i=0;i<N_;++i){
        string s=S[i];
        if(mp.find(s.substr(s.length()-3))!=mp.end()){
            for(auto u:mp[s.substr(s.length()-3)]){
                E[i].push_back(u);
                revE[u].push_back(i);
                cnt[i]++;
            }
        }
    }
    bfs();
    for(int k=0;k<N;++k){
        int i=lower_bound(S.begin(),S.end(),T[k])-S.begin();
        if(mem[i]==1)cout<<"Aoki"<<endl;
        else if(mem[i]==0)cout<<"Takahashi"<<endl;
        else cout<<"Draw"<<endl;
    }
}