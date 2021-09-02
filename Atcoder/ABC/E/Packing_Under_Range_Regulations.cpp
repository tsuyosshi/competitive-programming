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

int T;

signed main(){
    cin>>T;
    while(T--){
        int N;
        vector<PI> S;
        cin>>N;
        for(int i=0;i<N;++i){
            int l,r;
            cin>>l>>r;
            S.push_back(PI(l,r));
        }
        sort(S.begin(),S.end());
        queue<int> idx;
        priority_queue<int,vector<int>,greater<int>> que;
        idx.push(0);
        for(int i=1;i<N;++i){
            if(S[i].first==S[i-1].first)continue;
            idx.push(i);
        }
        idx.push(N);
        bool ok=true;
        while(true){
            int i=idx.front();
            idx.pop();
            if(i==N)break;
            int j=idx.front();
            for(int k=i;k<j;k++)que.push(S[k].second);
            int s=(int)que.size();
            int p=S[i].first;
            while(s--){
                int t=que.top();
                if(j!=N&&p>=S[j].first)break;
                if(t<p){
                    ok=false;
                    break;
                }
                que.pop();
                p++;
            }
            if(!ok)break;
        }
        if(!que.empty())ok=false;
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}