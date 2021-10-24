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

int L,R;
int cnt[1000005];
int ans;
vector<int> d[1000005];

vector<int> prime_factor(int x){
    vector<int> res;
    for(int p=2;p*p<=x;p++){
        int k=0;
        while(x%p==0){
            k++;
            x/=p;
        }
        if(k!=0)res.push_back(p);
    }
    if(x!=1)res.push_back(x);
    return res;
}

signed main(){
    cin>>L>>R;
    int ans=0;
    for(int x=L;x<=R;++x){
        d[x]=prime_factor(x);
        for(int bit=1;bit<(1<<d[x].size());++bit){
            int mul=1;
            for(int i=0;i<d[x].size();++i)if(bit&(1<<i))mul*=d[x][i];
            cnt[mul]++;
        }
    }
    for(int x=L;x<=R;++x){
        if(x==1)ans+=2*(R-x)+1;
        else ans+=2*(R-x-R/x+1);
    }
    for(int x=L;x<=R;++x){
        int num=(R-L+1);
        for(int bit=1;bit<(1<<d[x].size());++bit){
            int mul=1;
            for(int i=0;i<d[x].size();++i)if(bit&(1<<i))mul*=d[x][i];
            num+=cnt[mul]*(__builtin_popcount(bit)%2 ? (-1) : (+1));
        }
        ans-=num;
    }
    cout<<ans<<endl;
}