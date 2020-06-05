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
#include<limits.h>
#include <strings.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int IINF=INT32_MAX;
static const ll LINF=INT64_MAX;
static const ll mod=1e9+7;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N;
map<char, double> V;
vector<string> article;

int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int K;
        cin>>K;
        for(int j=0;j<K;++j){
            char c;
            int v;
            cin>>c;
            cin>>v;
            V[c]=v;
        }
        int M;
        cin>>M;
        getchar();
        for(int j=0;j<M;++j){
            string s;
            getline(cin,s);
            article.push_back(s);
        }
        double ans=0;
        for(auto line:article){
            for(int j=0;j<line.size();++j){
                decltype(V)::iterator it=V.find(line[j]);
                if(it!=V.end())ans+=V[line[j]];
            }
        }
        printf("%.2f$\n",(double)ans/100.0);
        article.clear();
        V.clear();
    }
}