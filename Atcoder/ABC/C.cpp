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
vector<string> S,T;

void rotate(vector<string> &X){
    vector<string> R;
    for(int i=0;i<N;++i){
        string r="";
        for(int j=0;j<N;++j){
            r+=X[j][N-1-i];
        }
        R.push_back(r);
    }
    X=R;
    /*cout<<"//////////////////////////////"<<endl;
    for(int i=0;i<X.size();++i){
        cout<<X[i]<<endl;
    }*/
}

bool check(){
    int sx,sy,tx,ty;
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(S[y][x]=='#'){
                sx=x;
                sy=y;
            }
            if(T[y][x]=='#'){
                tx=x;
                ty=y;
            }
        }
    }
    int rx=tx-sx,ry=ty-sy;
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(S[y][x]=='#'){
                int x_=x+rx,y_=y+ry;
                if(x_<0||x_>=N||y_<0||y_>=N){
                    return false;
                }
                if(T[y_][x_]=='.'){
                    return false;
                }
            }
            if(S[y][x]=='.'){
                int x_=x+rx,y_=y+ry;
                if(!(x_<0||x_>=N||y_<0||y_>=N)){
                    if(T[y_][x_]=='#')return false;
                }
            }
        }
    }
    return true;
}

signed main(){
    cin>>N;
    int cnt1=0,cnt2=0;
    for(int i=0;i<N;++i){
        string s;
        cin>>s;
        S.push_back(s);
    }
    for(int i=0;i<N;++i){
        string t;
        cin>>t;
        T.push_back(t);
    }
    for(int y=0;y<N;++y){
        for(int x=0;x<N;++x){
            if(S[y][x]=='#'){
                cnt1++;
            }
            if(T[y][x]=='#'){
                cnt2++;
            }
        }
    }
    if(cnt1!=cnt2){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<4;++i){
        rotate(S);
        if(check()){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}