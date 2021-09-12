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

string S;
int K;
map<PII,int> mem;

int calc(int n,int k,int isequal){
    if(mem.find(PII(n,PI(k,isequal)))!=mem.end())return mem[PII(n,PI(k,isequal))];
    if(n==S.size())return 0;
    int res=0;
    for(int i=0;i<=9;++i){
        if(n==0&&i==0)continue;
        int _isequal;
        if(isequal==1){
            if(i<S[n]-'0')_isequal=0;
            else if(i>S[n]-'0')_isequal=2;
            else _isequal=1;
        }
        else _isequal=isequal;
        if(n!=S.size()-1||_isequal!=2){
            if(k*i<=K)res++;
            res+=calc(n+1,k*i,_isequal);
        }
    }
    return mem[PII(n,PI(k,isequal))]=res;
}


signed main(){
    cin>>S;
    cin>>K;
    cout<<calc(0,1,1)<<endl;
}