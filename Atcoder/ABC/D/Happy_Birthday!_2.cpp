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

const int mod=200;
int N;
int A[205];
vector<int> dp1[205][205];
vector<int> dp2[205][205];

bool same(vector<int>& v1,vector<int>& v2){
    if(v1.size()!=v2.size())return false;
    for(int i=0;i<v1.size();++i){
        if(v1[i]!=v2[i])return false;
    }
    return true;
}

bool check(vector<int>& v1,vector<int>& v2){
    int m1=0,m2=0;
    for(auto u:v1)m1=(m1+A[u])%mod;
    for(auto u:v2)m2=(m2+A[u])%mod;
    return (m1==m2);
}

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A[i];
        A[i]%=mod;
    }
    for(int i=0;i<N;++i)dp1[i][A[i]%mod].push_back(i);
    for(int i=0;i<N;++i)dp2[i][A[i]%mod].push_back(i);
    for(int i=1;i<N;++i){
        for(int j=0;j<=mod;++j){
            if(dp1[i-1][(j-A[i]+mod)%mod].size()>0&&dp1[i][j].size()==0){
                dp1[i][j]=dp1[i-1][(j-A[i]+mod)%mod];
                dp1[i][j].push_back(i);
            }
            else if(dp1[i-1][j].size()>0&&dp1[i][j].size()==0){
                dp1[i][j]=dp1[i-1][j];
            }
        }
    }
    for(int i=1;i<N;++i){
        for(int j=0;j<=mod;++j){
            if(dp2[i-1][j].size()>0){
                dp2[i][j]=dp2[i-1][j];
            }
            else if(dp2[i-1][(j-A[i]+mod)%mod].size()>0){
                dp2[i][j]=dp2[i-1][(j-A[i]+mod)%mod];
                dp2[i][j].push_back(i);
            }
        }
    }
    for(int i=0;i<=mod;++i){
        if(dp1[N-1][i].size()==0)continue;
        if(!same(dp1[N-1][i],dp2[N-1][i])){
            if(!check(dp1[N-1][i],dp2[N-1][i]))cout<<1/0<<endl;
            cout<<"Yes"<<endl;
            cout<<dp1[N-1][i].size()<<" ";
            for(auto u:dp1[N-1][i])cout<<u+1<<" ";
            cout<<endl;
            cout<<dp2[N-1][i].size()<<" ";
            for(auto u:dp2[N-1][i])cout<<u+1<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}