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

struct team{
    string name;
    int points=0;
    int wins=0;
    int loses=0;
    int ties=0;
    int gd=0;
    int goals=0;
    int against=0;
    int played=0;
};

bool asc(const team& left, const team& right){
    if(left.points!=right.points)return left.points>right.points;
    if(left.wins!=right.wins)return left.wins>right.wins;
    if(left.gd!=right.gd)return left.gd>right.gd;
    if(left.goals!=right.goals)return left.goals>right.goals;
    if(left.played!=right.played)return left.played<right.played;
    return strcasecmp(left.name.c_str(),right.name.c_str())<0;
}

int main(){
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;++i){
        string tournament;
        getline(cin,tournament);
        int T;
        cin>>T;
        getchar();
        team t[55];
        map<string,int> tname;
        for(int j=0;j<T;++j){
            string name;
            getline(cin,name);
            t[j].name=name;
            tname[name]=j;
        }
        int G;
        cin>>G;
        getchar();
        char buf[110];
        for(int j=0;j<G;++j){
            gets(buf);
            char t1[50],t2[50];
            int p1,p2;
            sscanf(buf, "%[^#]#%d@%d#%[^\n]", t1, &p1, &p2, t2);
            if(p1>p2){
                t[tname[t1]].points+=3;
                t[tname[t1]].wins++;
                t[tname[t2]].loses++;
            }
            else if(p1<p2){
                t[tname[t2]].points+=3;
                t[tname[t2]].wins++;
                t[tname[t1]].loses++;
            }
            else {
                t[tname[t1]].points++;
                t[tname[t2]].points++;
                t[tname[t1]].ties++;
                t[tname[t2]].ties++;
            }
            t[tname[t1]].gd+=p1-p2;
            t[tname[t1]].goals+=p1;
            t[tname[t1]].against+=p2;
            t[tname[t1]].played++;
            t[tname[t2]].gd+=p2-p1;
            t[tname[t2]].goals+=p2;
            t[tname[t2]].against+=p1;
            t[tname[t2]].played++;
        }
        sort(t,t+T,asc);
        cout<<tournament<<endl;
        for(int i=0;i<T;++i){
            cout<<i+1<<") "<<t[i].name<<" "<<t[i].points<<"p, "<<t[i].played<<"g ("<<t[i].wins<<"-"<<t[i].ties<<"-"<<t[i].loses<<"), "<<t[i].gd<<"gd ("<<t[i].goals<<"-"<<t[i].against<<")"<<endl;
        }
        if(i!=N-1)cout<<endl;
        tname.clear();
    }
}