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

const int MAX_D=365;
const int MAX_type=26;
const int BeamWidth=200;

int D;
int c[MAX_D+5];
int s[MAX_D+5][MAX_type+5];

struct State{
    vector<int> contest;
    vector<int> last;
    int day;
    int score;

    State(){
        day=1;
        score=0;
        last.assign(MAX_type+5,0);
    }

    void update(int type){
        contest.push_back(type);
        last[type]=day;
        score+=s[day][type];
        for(int i=1;i<=MAX_type;++i){
            score-=c[i]*(day-last[i]);
        }
        day++;
    }

    State nextState(int type){
        State next;
        next=*this;
        next.update(type);
        return next;
    }
};

bool operator< (const State &state1, const State &state2){
    return state1.score < state2.score;
};

bool operator> (const State &state1, const State &state2){
    return state1.score > state2.score;
};

State beamsearch(){
    int D_=D;
    priority_queue<State, vector<State>, greater<State> > nowpq;
    for(int type=1;type<=MAX_type;++type){
        State s;
        nowpq.push(s.nextState(type));
    }
    while(nowpq.size()>BeamWidth)nowpq.pop();
    D_--;
    while(D_--){
        priority_queue<State, vector<State>, greater<State> > nextpq;
        while(nowpq.size()){
            State now=nowpq.top();
            nowpq.pop();
            for(int type=1;type<=MAX_type;++type){
                nextpq.push(now.nextState(type));
            }
        }
        while(nextpq.size()>BeamWidth)nextpq.pop();
        nowpq=nextpq;
    }
    while(nowpq.size()>1)nowpq.pop();
    State ret=nowpq.top();
    return ret;
}

void input(){
    cin>>D;
    for(int i=1;i<=MAX_type;++i)cin>>c[i];
    for(int i=1;i<=D;++i){
        for(int j=1;j<=MAX_type;++j){
            cin>>s[i][j];
        }
    }
}

signed main(){
    input();
    auto res=beamsearch();
    for(auto u:res.contest){
        cout<<u<<endl;
    }
}