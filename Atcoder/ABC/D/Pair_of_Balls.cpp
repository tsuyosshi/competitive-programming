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
queue<int> T[200005];
vector<int> b[200005];
int cnt[200005];
int check;

signed main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int k;
        cin>>k;
        for(int j=0;j<k;++j){
            int a;
            cin>>a;
            a--;
            T[i].push(a);
            b[a].push_back(i);
        }
    }
    queue<PI> que;
    for(int i=0;i<M;++i)cnt[T[i].front()]++;
    for(int i=0;i<N;++i)if(cnt[i]==2)que.push(PI(b[i][0],b[i][1]));
    while(que.size()){
        check++;
        int ta=que.front().first;
        int tb=que.front().second;
        que.pop();
        T[ta].pop();
        T[tb].pop();
        if(T[ta].size()){
            int c=T[ta].front();
            cnt[c]++;
            if(cnt[c]==2)que.push(PI(b[c][0],b[c][1]));
        }
        if(T[tb].size()){
            int c=T[tb].front();
            cnt[c]++;
            if(cnt[c]==2)que.push(PI(b[c][0],b[c][1]));
        }
    }
    if(check==N)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}