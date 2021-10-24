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

int N,M;
vector<int> E[25];
map<int,vector<int>> mp;
set<vector<int>> st;

bool check(vector<int> &comp,int bit){
	vector<int> color(comp.size(),-1);
	queue<int> que;
	que.push(0);
	color[0]=0;
	while(que.size()){
		int v=que.front();
		que.pop();
		for(auto e:E[comp[v]]){
			int u=lower_bound(comp.begin(),comp.end(),e)-comp.begin();
			int c=(bit&(1<<u))?1:2;
			if(color[u]==color[v]){
				return false;
			}
			if(color[u]!=-1){
				if(color[u]==color[v])return false;
				else continue;
			}
			color[u]=(color[v]+c)%3;
			que.push(u);
		}
	}
	if(st.find(color)!=st.end())return false;
	st.insert(color);
	return true;
}

signed main(){
    cin>>N>>M;
    UnionFind uf(N+5);
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        E[a].push_back(b);
        E[b].push_back(a);
        uf.unite(a,b);
    }
    for(int i=0;i<N;++i)mp[uf.find(i)].push_back(i);
	int ans=1;
    for(auto comp:mp){
		int cnt=0;
		for(int bit=0;bit<(1<<comp.second.size());++bit){
			if(check(comp.second,bit))cnt++;
		}
		cnt*=3;
		ans*=cnt;
		st.clear();
    }
	cout<<ans<<endl;
}