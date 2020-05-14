#include <bits/stdc++.h>

using namespace std;

int N,K;
int V[110];

int ans=0;
vector<int> v_minus;

int main(){

    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>V[i];

    int R=min(N,K);

    for(int A=0;A<=R;++A){
        for(int B=0;B<=R;++B){
            if(A+B>R)continue;
            int v=0;
            for(int i=0;i<A;++i){
                v+=V[i];
                if(V[i]<0)v_minus.push_back(V[i]);
            }
            for(int i=0;i<B;++i){
                v+=V[N-i-1];
                if(V[N-i-1]<0)v_minus.push_back(V[N-i-1]);
            }
            sort(v_minus.begin(),v_minus.end());
            for(int i=0;i<min((int)v_minus.size(),K-(A+B));++i)v-=v_minus[i];
            ans=max(ans,v);
            v_minus.clear();
        }
    }

    cout<<ans<<endl;

}