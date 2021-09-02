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
vector<int> A;
map<int,vector<int>> mp;
int ans;

signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i){
        int a;
        cin>>a;
        A.push_back(a);
        mp[a].push_back(i);
    }
    A.push_back(0);
    sort(A.begin(),A.end(),greater<int>());
    A.erase(unique(A.begin(),A.end()),A.end());
    int num=0;
    for(int i=0;i<A.size()-1;++i){
        int a=(int)mp[A[i]].size();
        num+=a;
        int d=(A[i]-A[i+1])*num;
        int D;
        if(d<=K){
            K-=d;
            D=(A[i]*(A[i]+1)-A[i+1]*(A[i+1]+1))*num/2;
            ans+=D;
        }
        else {
            int k=K/num;
            D=(A[i]*(A[i]+1)-(A[i]-k)*(A[i]+1-k))*num/2;
            D+=(A[i]-k)*(K%num);
            ans+=D;
            break;
        }
    }
    cout<<ans<<endl;
}