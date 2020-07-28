#include<bits/stdc++.h>

using namespace std;

#define MAX_N 20000

struct Vector2 {
    double x, y;
    Vector2() {}
    Vector2(double x, double y) : x(x), y(y) {}
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
    bool operator==(const Vector2 &other) {
        return (x == other.x && y == other.y);
    }
    double dot(Vector2 other) {
        return x * other.x + y * other.y;
    }
    double det(Vector2 other) {
        return x * other.y - y * other.x;
    }
    double norm() {
        return x * x + y * y;
    }
};

bool cmp_x(const Vector2 &p, const Vector2 &q) {
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

double square_dist(Vector2 &p, Vector2 &q) {
    return (p - q).norm();
}

double dist(Vector2 &p, Vector2 &q) {
    return sqrt(square_dist(p, q));
}

vector<Vector2> pos;
vector<vector<Vector2>> set_convexhull;

//凸包を求める, psはすでにsort済み
vector<Vector2> convexhull(vector<Vector2> &ps) {
    int size = ps.size();
    int k = 0;
    cout << size <<endl;
    if (size <= 2) return ps;
    vector<Vector2> qs(size * 2);
    for (int i = 0; i < size; ++i) {
        while (k > 1 && (qs[k -1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = size - 2, t = k; i >= 0; i--) {
        while(k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

//凸包で得た頂点を元の頂点集合から削除
void cut_convexhull(vector<Vector2> &inside_convexhull){
    for (auto vertex : inside_convexhull){
        cout << "target : " << vertex.x << " " << vertex.y <<endl;
        int idx = lower_bound(pos.begin(), pos.end(), vertex, cmp_x) - pos.begin();
        pos.erase(pos.begin() + idx);
        cout << "idx : " << idx << endl;
    }
}

int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        pos.push_back(Vector2(x, y));
    }
    sort(pos.begin(), pos.end(), cmp_x);
    while (pos.size() > 0) {
        //cout << pos.size() << endl;
        set_convexhull.push_back(convexhull(pos));
        cut_convexhull(set_convexhull[set_convexhull.size()-1]);
    }
    for (auto v : set_convexhull) {
        cout <<"####################################" <<endl;
        for (auto u : v) {
            cout << u.x << " " << u.y << endl;
        }
    }
    return 0;
}

/*
7
50 0
150 0
0 100
105 95
200 100
50 200
150 200
*/