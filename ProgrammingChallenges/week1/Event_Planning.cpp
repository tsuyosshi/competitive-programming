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
typedef long long ll;

int main(){
    int N,B,H,W;
    while(cin>>N>>B>>H>>W){
        int minc=INT32_MAX;
        bool stayable=false;
        for(int i=0;i<H;++i){
            int p;
            cin>>p;
            for(int j=0;j<W;++j){
                int a;
                cin>>a;
                if(a>=N&&p*N<=B){
                    stayable=true;
                    minc=min(p*N,minc);
                }
            }
        }
        if(stayable)cout<<minc<<endl;
        else cout<<"stay home"<<endl;
    }
}