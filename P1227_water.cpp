#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
const long long MOD = pow(10,9) + 7;
using namespace std;
struct Point {
    Point(int x_, int y_):x(x_),y(y_){}
    Point(){}
    int x, y;
    bool operator<(Point const& rhs) const {
        if (rhs.x == x) return y < rhs.y;
        return x < rhs.x;
    }
    friend Point operator+(Point const& x, Point const& y) {
        return Point(x.x +y.x,x.y+y.y);
    }
    bool operator==(Point const& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(Point const& rhs) const {
        return !(*this == rhs);
    }
};
vector<Point> p;
int N;
int main() {
    scanf("%d",&N);
    for (int i = 0; i < N;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        p.push_back(Point(x,y));
    }
    sort(p.begin(), p.end());
    int flag = 0;
    Point mid(p[0] + p[p.size() - 1]);
    for (int i = 1; i < p.size()/2; ++i) {


        if (p[i] + p[p.size() - 1 - i] != mid) {
                flag = 1;
                break;
        }
    }
    if (flag == 1) {
        printf("This is a dangerous situation!\n");
    }
    else {
        printf("V.I.P. should stay at (%.1f,%.1f).\n",mid.x * 1.0/2, mid.y * 1.0 / 2);
    }
}
