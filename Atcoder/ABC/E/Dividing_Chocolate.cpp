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

const ll INF=100000000;

int H,W,K;
string S[1005];

int choco[15][1005];
int B[15];

int Pow(int a,int b){
    int res=1;
    for(int i=0;i<b;++i)res*=a;
    return res;
}

int calc_choco(int x,int y,int pline_x,int pline_y){
    int cnt;
    if(pline_y==0){
        if(pline_x==0)cnt=choco[y-1][x-1];
        else cnt=choco[y-1][x-1]-choco[y-1][pline_x-1];
    }
    else if(pline_x==0)cnt=choco[y-1][x-1]-choco[pline_y-1][x-1];
    else cnt=choco[y-1][x-1]-choco[pline_y-1][x-1]-choco[y-1][pline_x-1]+choco[pline_y-1][pline_x-1];
    return cnt;
}

int calc(int b){
    int res=0;
    vector<int> line_y;
    int pline_x=0;
    int pline_y=0;
    for(int i=1;i<H;++i){
        if((b&B[i])==B[i])line_y.push_back(i);
    }
    line_y.push_back(H);
    //cout<<"y=";
    //for(auto u:line_y)cout<<u<<" ";
    //cout<<endl;
    for(int x=1;x<=W;++x){
        pline_y=0;
        int cnt;
        for(auto y:line_y){
            cnt=calc_choco(x,y,pline_x,pline_y);
            //cout<<"(pline_x,pline_y)="<<pline_x<<" "<<pline_y<<endl;
            //cout<<"(x,y)="<<x<<" "<<y<<endl;
            //cout<<"cnt="<<cnt<<endl;
            if(cnt>K){
                pline_x=x-1;
                res++;
            }
            if(x==W){
                cout<<calc_choco(x,y,pline_x,pline_y)<<endl;
                if(calc_choco(x,y,pline_x,pline_y)>K)return INF;
            }
            pline_y=y;
        }
    }
    return line_y.size()+res-1;
}

int main(){
    for(int i=0;i<15;++i)B[i]=Pow(2,i);
    int ans=10000005;
    cin>>H>>W>>K;
    for(int i=0;i<H;++i)cin>>S[i];
    for(int y=0;y<H;++y){
        for(int x=0;x<W;++x){
            int c=S[y][x]-'0';
            if(y==0){
                if(x==0)choco[y][x]=c;
                else choco[y][x]=choco[y][x-1]+c;
            }
            else {
                if(x==0)choco[y][x]=choco[y-1][x]+c;
                else choco[y][x]=choco[y-1][x]+(choco[y][x-1]-choco[y-1][x-1])+c;
            }
            //cout<<choco[y][x]<<endl;
        }
    }
    if(choco[H-1][W-1]<=K)cout<<0<<endl;
    else{
        for(int i=2;i<=B[H]-1;++i)ans=min(ans,calc(i));
        cout<<ans<<endl;
    }

}