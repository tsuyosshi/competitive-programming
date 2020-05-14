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

int N,M;
int X;
int C[20];
int A[20][20];

int B[20];

const int INF=1e8;

int pow(int x,int n){
    int res=1;
    for(int i=0;i<n;++i)res*=x;
    return res;
}

int calc(int b){
    int mon=0;
    for(int i=0;i<M;++i)B[i]=0;
    for(int i=0;i<N;++i){
        if((b&pow(2,i))!=pow(2,i))continue;
        for(int j=0;j<M;++j)B[j]+=A[i][j];
        mon+=C[i];
    }
    for(int i=0;i<M;++i){
        if(B[i]<X)return INF;
    }
    return mon;
}

int main(){
    cin>>N>>M>>X;
    for(int i=0;i<N;++i){
        cin>>C[i];
        for(int j=0;j<M;++j){
            cin>>A[i][j];
        }
    }
    int ans=INF;
    int maxbit=pow(2,N);
    for(int i=0;i<maxbit;++i)ans=min(ans,calc(i));
    if(ans!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;
}