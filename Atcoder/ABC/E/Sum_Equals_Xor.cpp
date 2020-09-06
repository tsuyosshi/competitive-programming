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

const int mod=1000000007;

string L;
int N;

PI ab[4]={PI(0,0),PI(0,1),PI(1,0),PI(1,1)};
int mem[100005][2][3];

void init(){
    for(int i=0;i<100005;++i)for(int j=0;j<2;++j)for(int k=0;k<3;++k)mem[i][j][k]=-1;
}

int check(int a, int b, int c, int dig){
    if(a+b+c>L[dig]-'0')return 2;
    if(a+b+c==L[dig]-'0')return 1;
    else return 0;
}

// isequal : 0=small, 1=equal, 2=bigger 
int calc(int n, int pre_c, int isequal){
    if(mem[n][pre_c][isequal]!=-1)return mem[n][pre_c][isequal];
    int ret=0;
    int a,b,c;
    int isequal_;
    if(n==N)return 0;
    for(int i=0;i<4;++i){
        a=ab[i].first,b=ab[i].second;
        if(a+b+pre_c>=2)c=1;
        else c=0;
        int same=check(a,b,pre_c,n);
        if(isequal==0||isequal==2){
            if(same==1)isequal_=isequal;
            else isequal_=same;
        }
        else isequal_=check(a,b,pre_c,n);
        if((a+b+pre_c)%2==a^b){
            if(!(n==N-1&&isequal_==2)){
                if((a==0&&b==0)||c!=0)ret+=calc(n+1,c,isequal_);
                else ret+=calc(n+1,c,isequal_)+1;
            }
            ret%=mod;
        }
    }
    return mem[n][pre_c][isequal]=ret%mod;
}

signed main(){
    init();
    cin>>L;
    N=L.size();
    reverse(L.begin(),L.end());
    cout<<(calc(0,0,1)+1)%mod<<endl;
    return 0;
}
