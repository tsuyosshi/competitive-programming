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

vector<string> file;
vector<string> temp;

bool ok(string org){
    int t=0;
    while(temp.size()){
        bool ok=false;
        string p1=temp[0];
        for(int i=1;i<temp.size();++i){
            string p2=temp[i];
            if(p1+p2==org||p2+p1==org){
                temp.erase(temp.begin());
                temp.erase(temp.begin()+i-1);
                ok=true;
                break;
            }
        }
        if(!ok){
            return false;
        }
        t++;
    }
    return true;
}

int main(){
    cin>>N;
    getchar();
    getchar();
    for(int i=0;i<N;++i){
        char buf[256];
        while(true){
            char *s;
            s=gets(buf);
            if(!(s&&*s))break;
            file.push_back(s);
        }
        //0番目とのペアを決定
        for(int j=1;j<file.size();++j){
            if(j>file.size())break;
            for(int k=0;k<file.size();++k)temp.push_back(file[k]);
            string org=temp[0]+temp[j];
            temp.erase(temp.begin());
            temp.erase(temp.begin()+j-1);
            if(ok(org)){
                cout<<org<<endl;
                break;
            }
            temp.clear();
            for(int k=0;k<file.size();++k)temp.push_back(file[k]);
            org=temp[j]+temp[0];
            temp.erase(temp.begin());
            temp.erase(temp.begin()+j-1);
            if(ok(org)){
                cout<<org<<endl;
                break;
            }
            temp.clear();
        }
        file.clear();
        temp.clear();
        if(i!=N-1)puts("");
    }
}