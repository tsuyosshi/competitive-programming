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

int N;
vector<PI> E[100005];
int color[100005];
bool painted[100005];

int main(){
    cin>>N;
    for(int i=0;i<N-1;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        E[a].push_back(PI(b,i));
        E[b].push_back(PI(a,i));
    }
    
    int K=0;
    for(int i=0;i<N;++i)K=max((int)E[i].size(),K);
    queue<PI> que;
    que.push(PI(0,-1));
    while(!que.empty()){
        int v=que.front().first;
        int p=que.front().second;
        que.pop();
        if(painted[v])continue;
        int t=0;
        for(auto u:E[v]){
            int to=u.first;
            int id=u.second;
            if(color[id]!=0)continue;
            if(t==p)t++;
            color[id]=t%K+1;
            que.push(PI(to,t%K));
            t++;
        }
        painted[v]=true;
    }
    cout<<K<<endl;
    for(int i=0;i<N-1;++i)cout<<color[i]<<endl;
}