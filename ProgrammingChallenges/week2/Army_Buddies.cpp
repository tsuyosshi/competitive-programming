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
typedef pair<int,int> PI;

PI v[100005];

int main(){
    int S,B;
    while(true){
        cin>>S>>B;
        if(S==0&&B==0)break;
        for(int i=0;i<100005;++i)v[i]=PI(i-1,i+1);
        for(int i=0;i<B;++i){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(v[l].first!=-1)cout<<v[l].first+1<<" ";
            else cout<<"* ";
            if(v[r].second<=S-1)cout<<v[r].second+1<<endl;
            else cout<<"*"<<endl;
            v[v[l].first].second=v[r].second;
            v[v[r].second].first=v[l].first;
        }
        cout<<"-"<<endl;
    }
}