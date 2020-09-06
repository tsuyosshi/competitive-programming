#include<bits/stdc++.h>

using namespace std;

static const double eps=1e-12;
double H = 1742.0, W = 2747.0;

struct Pos{
    double x, y;
    Pos() {}
    Pos(double x, double y) : x(x), y(y) {}
};

bool is_equal(double a, double b) {
    return abs(a - b) < eps;
}

bool is_equal(Pos a, Pos b) {
    return is_equal(a.x, b.x) && is_equal(a.y, b.y);
}

Pos get_destination(Pos s, double grad) {
    double x, y;
    // y - sy = grad * (x - sx)
    // y = 0, x = 0, y = H, x = W について解き条件に合うものを返す
    x = s.x - s.y / grad , y = 0.0;
    if(!is_equal(s.y, 0.0) && x >= 0.0 && x <= W) return Pos(x, y); 
    x = 0, y = s.y - grad * s.x;
    if(!is_equal(s.x, 0.0) && y >= 0.0 && y <= H) return Pos(x, y);
    x = s.x + (H - s.y) / grad , y = H;
    if(!is_equal(s.y, H) && x >= 0.0 && x <= W) return Pos(x, y); 
    x = W, y = s.y + grad * (W - s.x);
    if(!is_equal(s.x, W) && y >= 0.0 && y <= H) return Pos(x, y);
}

int main(){
    Pos p = Pos(W, 0);
    double grad = -1.0;
    map<string, int> cnt;
    cnt["bottom"] = 0, cnt["up"] = 0, cnt["left"] = 0, cnt["right"] = 0; 
    while(true) {
        p = get_destination(p, grad);
        cout << "p :" << p.x << ", " << p.y << endl;
        if(is_equal(p, Pos(0, 0)) || is_equal(p, Pos(0, H)) || is_equal(p, Pos(W, 0)) || is_equal(p, Pos(W, H))) break;
        if(is_equal(p.y, 0.0)) cnt["bottom"]++;
        if(is_equal(p.y, H)) cnt["up"]++;
        if(is_equal(p.x, 0.0)) cnt["left"]++;
        if(is_equal(p.x, W)) cnt["right"]++;
        grad = -grad;
    }
    cout <<"distination : " << p.x << ", " << p.y << endl;
    cout << "bottom : " << cnt["bottom"] << endl;
    cout << "up : " << cnt["up"] << endl;
    cout << "left : " << cnt["left"] << endl;
    cout << "right : " << cnt["right"] << endl;

}