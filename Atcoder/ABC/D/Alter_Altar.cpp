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
string S;

vector<int> ri;
int ans;

void swap(int i,int j){
    char temp=S[i];
    S[i]=S[j];
    S[j]=temp;
}

signed main(){
    cin>>N;
    cin>>S;
    for(int i=0;i<N;++i)if(S[i]=='R')ri.push_back(i);
    for(int i=0;i<N;++i){
        if(ri.size()==0)break;
        if(S[i]=='W'){
            int j=ri.back();
            if(j<i)break;
            swap(i,j);
            ans++;
            ri.pop_back();
        }
    }
    cout<<ans<<endl;
}