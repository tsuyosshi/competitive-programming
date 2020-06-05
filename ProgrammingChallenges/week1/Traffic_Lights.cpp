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
typedef long long ll;

const int maxtime = 5*3600;
const int maxsize = 1000000;

vector<int> cycletime;
int imos[maxsize];

void disp(int t){
    if(t<10)cout<<"0"<<t;
    else cout<<t;
}

void calc(){
    sort(cycletime.begin(),cycletime.end(),greater<int>());
    for(int i=0;i<cycletime.size();++i){
        if(i!=cycletime.size()-1){
            imos[1]+=1;
            imos[cycletime[i]-4]+=-1;
        }
        int t=0;
        while(t<=maxtime){
            t+=cycletime[i]*2;
            imos[t]+=1;
            imos[t+cycletime[i]-4]+=-1;
        }
    }
    for(int i=0;i<=maxtime;++i){
        imos[i+1]+=imos[i];
    }
    for(int i=0;i<=maxtime;++i){
        if(imos[i]==cycletime.size()&&imos[i+1]==cycletime.size()){
            int h=i/3600;
            int m=(i%3600)/60;
            int s=(i%3600)%60;
            disp(h);
            cout<<":";
            disp(m);
            cout<<":";
            disp(s);
            cout<<endl;
            return;
        }
    }
    cout<<"Signals fail to synchronise in 5 hours"<<endl;
    return;
}

int main(){

    while(true){
        int a;
        cin>>a;
        if(a==0){
            if(cycletime.size()<=1){
                cycletime.push_back(a);
                continue;
            }
            else if(cycletime.size()==2&&cycletime[0]==0&&cycletime[1]==0)break;
            calc();
            cycletime.clear();
            for(int i=0;i<1000000;++i)imos[i]=0;
        }
        else cycletime.push_back(a);
    }

}