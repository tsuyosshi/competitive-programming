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

using namespace std;
typedef long long int ll;

class UnionFind {
public:
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int N,M,K;
int rf[100005],blo[100005];
int ff[100005];

int main(){
    cin>>N>>M>>K;
    UnionFind uf(N+1);
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        ff[a]++,ff[b]++;
        uf.unite(a,b);
    }
    for(int i=0;i<N;++i){
        rf[uf.root(i)]++;
    }
    for(int i=0;i<K;++i){
        int c,d;
        cin>>c>>d;
        c--,d--;
        if(uf.same(c,d)){
            blo[c]++;
            blo[d]++;
        }
    }
    for(int i=0;i<N;++i){
        cout<<rf[uf.root(i)]-ff[i]-blo[i]-1<<endl;
    }
}