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
 
int N,K;
int A[200005];
 
vector<PI> pls;
vector<PI> mns;
bool used[200005];
 
int modPow(int a, int n){
    if(n==1)return a%mod;
    if(n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}
 
signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i){
        if(A[i]>=0)pls.push_back(PI(A[i],i));
        else mns.push_back(PI(A[i],i));
    }
    sort(pls.begin(),pls.end(),greater<PI>());
    sort(mns.begin(),mns.end());
    int ans=1;
    if(N==K){
        for(int i=0;i<N;++i){
            ans*=A[i];
            ans=(ans+mod)%mod;
        }
    }
    else if(pls.size()==0){
        if(K%2==0){
            for(int i=0;i<K;++i){
                ans*=mns[i].first;
                ans=(ans+mod)%mod;
            }
        }
        else {
            for(int i=0;i<K;++i){
                ans*=mns[N-i-1].first;
                ans=(ans+mod)%mod;
            }
        }
    }
    else {
        vector<int> res;
        int p=0,m=0;
        while(res.size()<K){
            if(p!=pls.size()&&m!=mns.size()){
                if(pls[p].first>abs(mns[m].first)){
                    res.push_back(pls[p].first);
                    used[pls[p].second]=true;
                    p++;
                }
                else {
                    res.push_back(mns[m].first);
                    used[mns[m].second]=true;
                    m++;
                }
            }
            else if(p!=pls.size()){
                res.push_back(pls[p].first);
                used[pls[p].second]=true;
                p++;
            }
            else {
                res.push_back(mns[m].first);
                used[mns[m].second]=true;
                m++;
            }
        }
        for(int i=0;i<K;++i){
            ans*=abs(res[i]);
            ans%=mod;
        }
        if(m%2!=0){
            int mi1=INF,mi2=INF;
            int ma1=-INF,ma2=-INF;
            for(int i=0;i<N;++i){
                if(used[i]&&A[i]<0)chmin(mi1,abs(A[i]));
                else if(!used[i]&&A[i]>=0) chmax(ma1,A[i]);
            }
            for(int i=0;i<N;++i){
                if(used[i]&&A[i]>0)chmin(mi2,A[i]);
                else if(!used[i]&&A[i]<0) chmax(ma2,abs(A[i]));
            }
            if((ma2==-INF||mi2==INF)||ma1*mi2>ma2*mi1){
                ans*=(ma1*modPow(mi1,mod-2))%mod;
                ans%=mod;
            }
            else {
                ans*=(ma2*modPow(mi2,mod-2))%mod;
                ans%=mod;
            }
        }
    }
    cout<<(ans+mod)%mod<<endl;
}