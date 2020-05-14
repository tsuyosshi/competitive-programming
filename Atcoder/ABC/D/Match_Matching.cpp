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

const int INF=1e8;

int N,M;
vector<int> A;

int match[9]={2,5,5,4,5,6,3,7,6};
vector<int> usematch[9];

string dp[100005];

//(a>b)
bool comp(string a,string b){
    //cout<<a<<" "<<b<<endl;
    if(a.size()<b.size())return false;
    else if(a.size()>b.size())return true;
    return (a>b);
}

int main(){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a;
        cin>>a;
        usematch[match[a-1]].push_back(a);
    }
    for(int i=0;i<100005;++i)dp[i]="";
    for(int i=0;i<=N;++i){
        if(i!=0&&dp[i]=="")continue;
        for(int j=0;j<=9;++j){
            for(int k=0;k<usematch[j].size();++k){
                int a=usematch[j][k];
                if(comp(dp[i]+(char)(a+'0'),dp[i+j]))dp[i+j]=dp[i]+(char)(a+'0');
            }
        }
    }
    cout<<dp[N]<<endl;
}