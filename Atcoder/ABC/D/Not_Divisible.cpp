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

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;
int A[200005];
bool used[2000000];
int num[2000000];

int res;

bool divisor(int n) {
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            if(used[i])return true;
            if (i*i!=n&&used[n/i])return true;
        }
    }
    return false;
}

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>A[i];
        num[A[i]]++;
    }
    sort(A,A+N);
    for(int i=0;i<N;++i){
        if(divisor(A[i])||num[A[i]]>1)res++;
        used[A[i]]=true;
    }
    cout<<N-res<<endl;
}