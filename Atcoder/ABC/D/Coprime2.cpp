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
int A[100005];
int Q[100005];
int cnt;

void prime_factor(int x){
    for(int p=2;p*p<=x;p++){
        int k=0;
        while(x%p==0){
            k++;
            x/=p;
        }
        if(k!=0)Q[p]=k;
    }
    if(x!=1)Q[x]=1;
}

bool check(int x){
    for(int p=2;p*p<=x;p++){
        int k=0;
        while(x%p==0){
            k++;
            x/=p;
        }
        if(k!=0&&Q[p]!=0) return false;
    }
    if(x!=1&&Q[x]!=0)return false;
    return true;
}

signed main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>A[i];
        prime_factor(A[i]);
    }
    for(int q=1;q<=M;++q)if(check(q))cnt++;
    cout<<cnt<<endl;
    for(int q=1;q<=M;++q)if(check(q))cout<<q<<endl;
}