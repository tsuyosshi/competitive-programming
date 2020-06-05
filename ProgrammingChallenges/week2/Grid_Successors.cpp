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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


char g[3][3];
int h[3][3];

int N;

void simulate(){
    for(int y=0;y<3;++y){
        for(int x=0;x<3;++x){
            h[y][x]=0;
            for(int i=0;i<4;++i){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||nx>=3||ny<0||ny>=3)continue;
                h[y][x]+=g[ny][nx]-'0';
                h[y][x]%=2;
            }
        }
    }
    for(int y=0;y<3;++y){
        for(int x=0;x<3;++x){
            g[y][x]=h[y][x]+'0';
        }
    }
}

bool check(){
    for(int y=0;y<3;++y){
        for(int x=0;x<3;++x){
            if(g[y][x]!='0')return true;
        }
    }
    return false;
}

int main(){
    cin>>N;
    while(N--){
        for(int i=0;i<3;++i)for(int j=0;j<3;++j)cin>>g[i][j];
        int ans=-1;
        while(check()){
            simulate();
            ans++;
        }
        cout<<ans<<endl;
    }
}
