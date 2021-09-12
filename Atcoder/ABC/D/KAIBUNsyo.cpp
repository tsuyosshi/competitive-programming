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
int A[200005];

class UnionFind {
private:
	vector<int> par;
	vector<int> siz;
 
public:
	UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(int sz_) {
		par.resize(sz_);
		siz.resize(sz_, 1);
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}
	int find(int x) {
		while (par[x] != x) x = par[x] = par[par[x]];
		return x;
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (siz[x] < siz[y]) std::swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return siz[find(x)];
	}
};

int ans=0;
bool flag[200005];

signed main(){
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
    UnionFind uf(200005);
    for(int i=0;i<N;++i){
        if(A[i]!=A[N-i-1]){
            uf.unite(A[i],A[N-i-1]);
        }
    }
    for(int i=0;i<N;++i){
        if(flag[uf.find(A[i])])continue;
        else {
            ans+=uf.size(A[i])-1;
            flag[uf.find(A[i])]=true;
        }
    }
    cout<<ans<<endl;
}