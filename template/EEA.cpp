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

// st d=gcd(f,g) s*f+t*g=d

int s,t,d;

tuple<int,int,int> EEA(int f,int g){
    int r0=f,s0=1,t0=0;
    int r1=g,s1=0,t1=1;
    int r2,s2,t2;
    int step=1;
    while(r1!=0){
        step++;
        int q=r0/r1;
        r2=r0%r1;
        s2=s0-q*s1;
        t2=t0-q*t1;
        //cout<<"step"<<step<<endl;
        //printf("(%lld,%lld,%lld)-%lld(%lld,%lld,%lld)=(%lld,%lld,%lld)\n",r0,s0,t0,q,r1,s1,t1,r2,s2,t2);
        r0=r1,r1=r2;
        s0=s1,s1=s2;
        t0=t1,t1=t2;
    }
    d=r0,s=s0,t=t0;
    return make_tuple(s,t,d);
}

int CTR(vector<int> &n,vector<int> &a){
    // n = a (mod m)
    int dim=n.size();
    int r=1;
    int x=0;
    vector<int> e;
    for(int i=0;i<dim;++i)r*=n[i];
    for(int i=0;i<dim;++i){
        int r_=r/n[i];
        int r_inv=(get<0>(EEA(r_,n[i]))+n[i])%n[i];
        e.push_back(r_inv*r_);
    }
    for(int i=0;i<dim;++i){
        x+=a[i]*e[i];
        x%=r;
    }
    return x;
}

signed main(){
    int n1=9,n2=13,n3=17;
    int n=n1*n2*n3;
    int n1_=n2*n3,n2_=n3*n1,n3_=n1*n2;
    cout << "n1*="<<n1_<<endl;
    int n1_inv = (get<0>(EEA(n1_,n1)) + n1)%n1 ;
    cout << "n1*_inv=" << n1_inv << endl;
    int e1 = n1_inv *  n1_;
    cout << "e1=" << e1 <<endl;
    cout << "n2*="<<n2_<<endl;
    int n2_inv = (get<0>(EEA(n2_,n2)) + n2)%n2;
    cout << "n2*_inv=" << n2_inv << endl;
    int e2 = n2_inv * n2_;
    cout << "e2=" << e2 <<endl;
    cout << "n3*="<<n3_<<endl;
    int n3_inv = (get<0>(EEA(n3_,n3)) + n3)%n3;
    cout << "n3*_inv=" << n3_inv << endl;
    int e3 = n3_inv * n3_;
    cout << "e3=" << e3 <<endl;
    int a1=2,a2=3,a3=7;
    int a=(a1*e1+a2*e2+a3*e3);
    cout<<"a="<<a<<endl;
    cout<<"a%n1="<<a%n1<<endl;
    cout<<"a%n2="<<a%n2<<endl;
    cout<<"a%n3="<<a%n3<<endl;
    for(int x=-n;x<=n;++x){
        if((x%n1+n1)%n1==a1&&(x%n2+n2)%n2==a2&&(x%n3+n3)%n3==a3){
            cout<<"x="<<x<<endl;
        }
    }
}