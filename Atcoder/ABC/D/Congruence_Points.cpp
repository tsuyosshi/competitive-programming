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

int N;

template<typename T>
struct Vector2 {
    T x, y;
    Vector2() {}
    Vector2(T x, T y) : x(x), y(y) {}
    void operator=(const Vector2 &other) {
        x = other.x;
        y = other.y;
    }
    Vector2 operator+(const Vector2 &other) {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector2 &other) {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(const T &scalar) {
        return Vector2(x * scalar, y * scalar);
    }
    Vector2 operator/(const T &scalar) {
        return Vector2(x / scalar, y / scalar);
    }
    bool operator==(const Vector2 &other) {
        return (x == other.x && y == other.y);
    }
    T dot(const Vector2 other) {
        return x * other.x + y * other.y;
    }
    T norm() {
        return dot(*this);
    }
    T det(const Vector2 other) {
        return x * other.y - y * other.x;
    }
};
 
template<typename T>
bool cmp_x(const Vector2<T> &p, const Vector2<T> &q) {
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

vector<Vector2<double>> S;
vector<Vector2<double>> T;
Vector2<double> mu1(0,0),mu2(0,0);

signed main(){
    cin>>N;
    for(int i=0;i<N;++i){
        double a,b;
        cin>>a>>b;
        Vector2<double> s(a,b);
        S.push_back(s*N);
        mu1=mu1+s;
    }
    for(int i=0;i<N;++i){
        double c,d;
        cin>>c>>d;
        Vector2<double> t(c,d);
        T.push_back(t*N);
        mu2=mu2+t;
    }
    for(int i=0;i<N;++i){
        S[i]=S[i]-mu1;
        T[i]=T[i]-mu2;
    }
    for(int i=0;i<N;++i){
        if(S[i].x==0&&S[i].y==0)continue;
        swap(S[i],S[0]);
    }
    for(int i=0;i<N;++i){
        Vector2<double> s=S[0];
        Vector2<double> t=T[i];
        double theta=atan2(t.y,t.x)-atan2(s.y,s.x);
        vector<Vector2<double>> R;
        for(int j=0;j<N;++j){
            double rx=S[j].x*cos(theta)-S[j].y*sin(theta);
            double ry=S[j].x*sin(theta)+S[j].y*cos(theta);
            Vector2<double> r(rx,ry);
            R.push_back(r);
        }
        bool check=true;
        for(int j=0;j<N;++j){
            bool flag=false;
            for(int k=0;k<N;++k){
                if(abs(R[j].x-T[k].x)<eps&&abs(R[j].y-T[k].y)<eps){
                    flag=true;
                    break;
                }
            }
            check&=flag;
            if(!check)break;
        }
        if(check){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
