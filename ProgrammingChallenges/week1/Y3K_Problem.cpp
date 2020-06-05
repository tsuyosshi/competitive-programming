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

//y,m,dの経過日数
int calc_days(int y,int m,int d){
    if (m <= 2){
        y--;
        m+=12;
    }
    int dy=365*(y-1); // 経過年数×365日
    int c=y/100;
    int dl=(y >> 2)-c+(c >> 2); // うるう年分
    int dm=(m*979-1033)>>5; // 1月1日から m 月1日までの日数
    return dy+dl+dm+d-1;
}

int main(){
    int N;
    int d,m,y;
    int md[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(true){

        cin>>N>>d>>m>>y;

        if(N==0&&d==0&&m==0&&y==0)break;

        //1年1月1日からの経過日数に換算
        N+=calc_days(y,m,d);

        int Y,M,D;
        //二分探索でYを求める
        int ly=0,ry=10000000;
        int mid;
        for(int i=0;i<100;++i){
            mid=(ly+ry)/2;
            if(N<=calc_days(mid,1,1))ry=mid;
            else ly=mid;
        }

        Y=mid,M=1,D=1;
        //Y年1月1日からの日数に換算
        N=N-calc_days(Y,1,1)+1;

        //残りの日数をシミュレーション
        while (true){
            if((Y%4==0&&Y%100!=0)||Y%400==0)md[1]=29;
            else md[1]=28;

            if(N>md[M-1]){
                N-=md[M-1];
                if(M==12){
                    M=1;
                    Y++;
                }
                else M++;
            }

            else {
                D=N;
                break;
            }
        }

        cout<<D<<" "<<M<<" "<<Y<<endl;

    }


}