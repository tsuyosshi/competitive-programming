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
int score[3];
int T[100005];

int dp[100005];
int ans;

signed main(){
    cin>>N>>K;
    cin>>score[0]>>score[1]>>score[2];
    for(int i=0;i<N;++i){
        char c;
        cin>>c;
        if(c=='r')T[i]=0;
        if(c=='s')T[i]=1;
        if(c=='p')T[i]=2;
    }
    for(int i=0;i<K;++i){
        int pret=-1;
        for(int j=i;j<N;j+=K){
            int t=(T[j]+2)%3;
            if(pret!=t){
                dp[i]+=score[t];
                pret=t;
            }
            else {
                if(j+K>=N)continue;
                int nt=(T[j+K]+2)%3;
                pret=(nt+2)%3;
            }
        }
    }
    for(int i=0;i<K;++i)ans+=dp[i];
    cout<<ans<<endl;
}