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

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(){

    }

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};

int N,Q;
string S;

BIT bit[27];

int main(){
    cin>>N;
    cin>>S;
    cin>>Q;
    for(int i=0;i<27;++i)bit[i]=BIT(N+1);
    for(int i=0;i<N;++i){
        int c=S[i]-'a';
        bit[c].add(i+1,1);
    }
    for(int i=0;i<Q;++i){
        int q;
        cin>>q;
        if(q==1){
            int iq;
            char cq;
            cin>>iq>>cq;
            iq--;
            if(S[iq]==cq)continue;
            bit[S[iq]-'a'].add(iq+1,-1);
            bit[cq-'a'].add(iq+1,1);
            S[iq]=cq;
        }
        else {
            int l,r;
            cin>>l>>r;
            int v=0;
            for(int j=0;j<27;++j){
                int x=bit[j].sum(r)-bit[j].sum(l-1);
                if(x>0)v++;
            }
            cout<<v<<endl;
        }
    }
}