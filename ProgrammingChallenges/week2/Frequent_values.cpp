#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<limits.h>
#include <strings.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

const int MAX_N=100000;

int node[400005];
int n;

class SegmentTree{
public:
    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        for(int i=0;i<2*n-1;i++)node[i]=-IINF;
    }
    void clear(){
        for(int i=0;i<400005;i++)node[i]=-IINF;
    }
    void update(int a,int x){
        a+=n-1;
        node[a]=x;
        while(a>0){
            a=(a-1)/2;
            node[a]=max(node[2*a+1],node[2*a+2]);
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=n){
        if(b<=l||r<=a)return -IINF;
        if(a<=l&&r<=b)return node[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
};

int N,Q;
int A[MAX_N+5];
vector<int> L;

int main(){
    while(true){
        cin>>N;
        if(N==0)break;
        cin>>Q;
        SegmentTree seg(N+5);
        for(int i=0;i<N;++i)cin>>A[i];
        int id=0;
        seg.update(0,1);
        L.push_back(0);
        for(int i=1;i<N;++i){
            if(A[i]!=A[i-1]){
                id=i;
                seg.update(id,1);
                L.push_back(id);
            }
            else seg.update(id,node[id+n-1]+1);
        }
        for(int i=0;i<Q;++i){
            int l,r;
            int ans=0;
            cin>>l>>r;
            l--,r--;
            if(l==r){
                cout<<1<<endl;
                continue;
            }
            int lid=lower_bound(L.begin(),L.end(),l)-L.begin();
            int rid=upper_bound(L.begin(),L.end(),r)-L.begin()-1;
            if(rid<lid){
                cout<<r-l+1<<endl;
                continue;
            }
            else{
                if(lid!=rid)chmax(ans,seg.query(L[lid],L[rid]));
                if(l!=L[lid])chmax(ans,L[lid]-l);
                if(r!=L[rid])chmax(ans,r-L[rid]+1);
                cout<<ans<<endl;
            }
        }
        L.clear();
        seg.clear();
    }
}