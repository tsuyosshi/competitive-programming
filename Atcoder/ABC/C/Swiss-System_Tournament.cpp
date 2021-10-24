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
vector<int> A[150];
vector<int> r(150);
vector<int> win(150);

signed main(){
    cin>>N>>M;
    for(int i=1;i<=2*N;++i){
        string s;
        cin>>s;
        for(int j=0;j<M;++j){
            int a;
            if(s[j]=='G')a=0;
            if(s[j]=='C')a=1;
            if(s[j]=='P')a=2;
            A[i].push_back(a);
        }
    }
    for(int i=1;i<=2*N;++i){
        r[i]=i;
        win[i]=0;
    }
    for(int j=0;j<M;++j){
        vector<PI> temp;
        for(int k=1;k<=N;++k){
            int a=r[2*k-1],b=r[2*k];
            int ja=A[a][j],jb=A[b][j];
            //cout<<a<<" "<<b<<endl;
            if(ja==jb)continue;
            if((ja+2)%3==jb){
                win[b]++;
            }
            else {
                win[a]++;
            }
        }
        for(int k=1;k<=2*N;++k){
            //cout<<"k, win : "<<k<<" "<<win[k]<<endl;
            temp.push_back(PI(-win[k],k));
        }
        sort(temp.begin(),temp.end());
        for(int k=1;k<=2*N;++k){
            r[k]=temp[k-1].second;
        }
    }
    for(int i=0;i<2*N;++i){
        cout<<r[i+1]<<endl;
    }
}