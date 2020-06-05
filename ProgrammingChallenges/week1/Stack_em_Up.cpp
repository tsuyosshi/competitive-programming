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


int shuffle[110][55];
int card[52];

string value_s[13]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
string suit_s[4]={"Clubs","Diamonds","Hearts","Spades"};

int main(){
    int T;
    bool kuso=false;
    while(cin>>T){
        for(int i=0;i<T;++i){
            for(int j=0;j<52;++j)card[j]=j;
            int N;
            cin>>N;
            for(int j=0;j<N;++j)for(int k=0;k<52;++k){
                cin>>shuffle[j][k];
                shuffle[j][k]--;
            }
            char buf[256];
            char* s;
            int t=0;
            while(true){
                s=gets(buf);
                if(!(s&&*s)){
                    t++;
                    if(t>=2)break;
                    continue;
                }
                int id_shuffle= atoi(s); 
                id_shuffle--;           
                int temp[52];
                for(int j=0;j<52;++j)temp[j]=card[j];
                for(int j=0;j<52;++j){
                    int id=shuffle[id_shuffle][j];
                    card[j]=temp[id];
                }
                
            }

            if(kuso)cout<<endl;
            else kuso=true;

            for(int j=0;j<52;++j){
                cout<<value_s[card[j]%13]<<" of "<<suit_s[card[j]/13]<<endl;
            }
            
        }
    }
}