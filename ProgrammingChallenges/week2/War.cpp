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


const int MAX_N=10000;
int N;

int main(){
    cin>>N;
    UnionFind uf(2*MAX_N+5);
    while(true){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==0&&a==0&&b==0)break;
        if(op==1){
            if(uf.same(a,b+MAX_N)||uf.same(a+MAX_N,b))cout<<-1<<endl;
            else{
                uf.unite(a,b);
                uf.unite(a+MAX_N,b+MAX_N);
            }
        }
        else if(op==2){
            if(uf.same(a,b)||uf.same(a+MAX_N,b+MAX_N))cout<<-1<<endl;
            else {
                uf.unite(a,b+MAX_N);
                uf.unite(a+MAX_N,b);
            }
        }
        else if(op==3)cout<<uf.same(a,b)<<endl;
        else if(op==4)cout<<(uf.same(a,b+MAX_N)||uf.same(a+MAX_N,b))<<endl;
    }

}