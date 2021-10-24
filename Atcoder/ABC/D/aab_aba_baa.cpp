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

map<PI, int> mem;

int comb(int n,int k){
    if(mem.find(PI(n,k))!=mem.end())return mem[PI(n,k)];
    if(n<k)return 0;
    if (n==k||k==0)return 1;
    int res=comb(n-1,k-1)+comb(n-1,k);
    return mem[PI(n,k)]=res;
}

int A,B;
int K;

signed main(){
    cin>>A>>B>>K;
    int a=0,b=0;
    int k=1;
    string ans="";
    for(int i=A+B;i>=1;--i){
        if(b<B&&k+comb(i-1,B-b)<=K){
            k+=comb(i-1,B-b);
            ans+='b';
            b++;
        }
        else {
            if(a<A){
                ans+='a';
                a++;
            }
            else {
                ans+='b';
                k+=comb(i-1,B-b);
                b++;
            }
        }
    }
    cout<<ans<<endl;
}