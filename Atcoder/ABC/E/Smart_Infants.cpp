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

const int MAX_N=200000;
int N,Q;
int A[200005],B[200005];

vector<int> q[200005];

int node[600005];
int n;

class SegmentTree{
public:
    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        for(int i=0;i<2*n-1;i++)node[i]=INF;
    }
    void update(int a,int x){
        a+=n-1;
        node[a]=x;
        while(a>0){
            a=(a-1)/2;
            node[a]=min(node[2*a+1],node[2*a+2]);
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=n){
        if(b<=l||r<=a)return INF;
        if(a<=l&&r<=b)return node[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
};

signed main(){
    cin>>N>>Q;
    SegmentTree seg(MAX_N);
    for(int i=0;i<N;++i){
        cin>>A[i]>>B[i];
        q[B[i]].push_back(A[i]);
    }
    for(int i=0;i<MAX_N;++i){
        if(q[i].size()==0)continue;
        sort(q[i].begin(),q[i].end());
        seg.update(i,q[i][q[i].size()-1]);
    }
    while(Q--){
        int C,D;
        cin>>C>>D;
        C--;
        int c=B[C]; 
        int id1=lower_bound(q[c].begin(),q[c].end(),A[C])-q[c].begin();
        int id2=lower_bound(q[D].begin(),q[D].end(),A[C])-q[D].begin();
        q[c].erase(q[c].begin()+id1);
        q[D].insert(q[D].begin()+id2,A[C]);
        if(q[c].size()==0)seg.update(c,INF);
        else seg.update(c,q[c][q[c].size()-1]);
        if(q[D].size()==0)seg.update(D,INF);
        else seg.update(D,q[D][q[D].size()-1]);
        cout<<seg.query(0,MAX_N)<<endl;
        B[C]=D;
    }
}