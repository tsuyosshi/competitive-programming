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


int N;
string S;
int r[4005],g[4005],b[4005];
int main(){
    cin>>N;
    cin>>S;
    for(int i=0;i<N;++i){
        if(S[i]=='R')r[i]++;
        else if(S[i]=='G')g[i]++;
        else if(S[i]=='B')b[i]++;
        if(i!=0){
            r[i]+=r[i-1];
            g[i]+=g[i-1];
            b[i]+=b[i-1];
        }
    }
    int ans=0;
    for(int i=0;i<N-2;++i){
        for(int j=i+1;j<N-1;++j){
            string s="";
            s+=S[i];
            s+=S[j];
            sort(s.begin(),s.end());
            if(s=="BG")ans+=r[N-1]-r[j];
            else if(s=="BR")ans+=g[N-1]-g[j];
            else if(s=="GR") ans+=b[N-1]-b[j];
            if(s[0]!=s[1]&&2*j-i<=N-1){
                s+=S[2*j-i];
                sort(s.begin(),s.end());
                if(s=="BGR")ans--;
            }
        }
    }

   cout<<ans<<endl;

}