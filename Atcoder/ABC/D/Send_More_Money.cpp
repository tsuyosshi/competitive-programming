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

string S1,S2,S3;
map<char,int> mp;
vector<int> perm;
vector<int> ans;
bool ok=false;
bool used[10];
int N;

bool check(){
    int c=0;
    if(perm[mp[S1[S1.size()-1]]]==0||perm[mp[S2[S2.size()-1]]]==0||perm[mp[S3[S3.size()-1]]]==0)return false;
    for(int i=0;i<S3.size();++i){
        int d=c;
        if(i<S1.size())d+=perm[mp[S1[i]]];
        if(i<S2.size())d+=perm[mp[S2[i]]];
        int m=d%10;
        if(m!=perm[mp[S3[i]]])return false;
        c=d/10;
    }
    if(c!=0)return false;
    else return true;
}

void dfs(int n){
    if(n==N){
        if(check()){
            if(!ok){
                for(auto u:perm)ans.push_back(u);
            }
            ok=true;
        }
        return;
    }
    for(int i=0;i<10;++i){
        if(used[i])continue;
        perm.push_back(i);
        used[i]=true;
        dfs(n+1);
        perm.pop_back();
        used[i]=false;
    }
}

signed main(){
    cin>>S1;
    cin>>S2;
    cin>>S3;
    reverse(S1.begin(),S1.end());
    reverse(S2.begin(),S2.end());
    reverse(S3.begin(),S3.end());
    for(int i=0;i<S1.size();++i){
        if(mp.find(S1[i])==mp.end()){
            mp[S1[i]]=N;
            N++;
        }
    }
    for(int i=0;i<S2.size();++i){
        if(mp.find(S2[i])==mp.end()){
            mp[S2[i]]=N;
            N++;
        }
    }
    for(int i=0;i<S3.size();++i){
        if(mp.find(S3[i])==mp.end()){
            mp[S3[i]]=N;
            N++;
        }
    }
    if(N>10)cout<<"UNSOLVABLE"<<endl;
    else {
        dfs(0);
        if(ans.size()==0)cout<<"UNSOLVABLE"<<endl;
        else {
            for(int i=S1.size()-1;i>=0;--i)cout<<ans[mp[S1[i]]];
            cout<<endl;
            for(int i=S2.size()-1;i>=0;--i)cout<<ans[mp[S2[i]]];
            cout<<endl;
            for(int i=S3.size()-1;i>=0;--i)cout<<ans[mp[S3[i]]];
            cout<<endl;
        }
    }
}