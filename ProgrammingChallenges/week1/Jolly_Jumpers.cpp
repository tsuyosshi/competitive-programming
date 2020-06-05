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

int main(){

    int n;
    vector<int> dif;
    while(cin>>n){
        bool isJumper=true;
        if(n==1){
            int a;
            cin>>a;
            cout<<"Jolly"<<endl;
        }
        else{
            int v=0,pv=0;
            for(int i=0;i<n;++i){
                cin>>v;
                if(i>0)dif.push_back(abs(v-pv));
                pv=v;
            }
            sort(dif.begin(),dif.end());
            for(int i=1;i<=n-1;++i){
                if(i!=dif[i-1])isJumper=false;
            }
            if(isJumper)cout<<"Jolly"<<endl;
            else cout<<"Not jolly"<<endl;
            dif.clear();
        }
    }
    /*string str, s;
    vector<string> v;
    vector<int> dif;
    while(getline(cin,str)){
        stringstream ss{str};
        bool isJumper=false;
        while(getline(ss,s,' ')){
            v.push_back(s);
        }
        for(int i=0;i<v.size()-1;++i){
            int n=atoi(v[i].c_str());
            int nn=atoi(v[i+1].c_str());
            dif.push_back(abs(n-nn));
        }
        for(auto u:dif){
            cout<<u<<endl;
            int t=0;
            for(auto w:v){

        if(isJumper)cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;
        v.clear();
        dif.clear();
    }*/
}