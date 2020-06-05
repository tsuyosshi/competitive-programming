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

int n;
vector<string> matrix;

int N;
int sum[30][30];

int calc(int x,int y){
    int res=0;
    for(int row=y;row<N;++row){
        for(int col=x;col<N;++col){
            int cnt;
            if(y==0){
                if(x==0)cnt=sum[row][col];
                else cnt=sum[row][col]-sum[row][x-1];
            }
            else if(x==0)cnt=sum[row][col]-sum[y-1][col];
            else cnt=sum[row][col]-sum[y-1][col]-sum[row][x-1]+sum[y-1][x-1];
            if(cnt==(col-x+1)*(row-y+1))chmax(res,cnt);
        }
    }
    return res;
}

int main(){
    cin>>n;
    getchar();
    getchar();
    while(n--){
        char buf[256];
        while(true){
            char *s;
            s=gets(buf);
            if(!(s&&*s))break;
            matrix.push_back(s);
        }
        N=matrix.size();
        //二次元累積和
        for(int row=0;row<N;++row){
            for(int col=0;col<N;++col){
                int c=matrix[row][col]-'0';
                if(row==0){
                    if(col==0)sum[row][col]=c;
                    else sum[row][col]=sum[row][col-1]+c;
                }
                else {
                    if(col==0)sum[row][col]=sum[row-1][col]+c;
                    else sum[row][col]=sum[row-1][col]+(sum[row][col-1]-sum[row-1][col-1])+c;
                }
            }
        }
        int ans=0;
        for(int y=0;y<N;++y){
            for(int x=0;x<N;++x){
                chmax(ans,calc(x,y));
            }
        }
        cout<<ans<<endl;
        if(n!=0)cout<<endl;
        for(int i=0;i<30;++i)for(int j=0;j<30;++j)sum[i][j]=0;
        matrix.clear();
    }
}