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

int N;
map<char,int> dic;
vector<string> Name;

bool cmp(const string& s1,const string& s2){
    int n=min(s1.size(),s2.size());
    for(int i=0;i<n;++i){
        if(dic[s1[i]]<dic[s2[i]])return true;
        else if(dic[s1[i]]>dic[s2[i]])return false;
    }
    if(s1.size()<=s2.size())return true;
    else return false;
}

signed main(){
    for(int i=0;i<26;++i){
        char c;
        cin>>c;
        dic[c]=i;
    }
    cin>>N;
    for(int i=0;i<N;++i){
        string s;
        cin>>s;
        Name.push_back(s);
    }
    sort(Name.begin(),Name.end(),cmp);
    for(auto name:Name)cout<<name<<endl;
}