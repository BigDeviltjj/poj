#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
double a[6][2], x0, y_0, x1, y_1;
double a0,a1,a2,a3;
int n;
vector<int> seq;
double dist(int i, int j) {
    return sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]));
}
double getArea(vector<int>& seq) {
    vector<double> rs;
    double ret;
    for (int i = 0; i < seq.size(); ++i) {
        priority_queue<double, vector<double>, greater<double> > qi;
        qi.push(a[seq[i]][0]);
        qi.push(a[seq[i]][1]);
        qi.push(x1 - a[seq[i]][0]);
        qi.push(y_1 - a[seq[i]][1]);
        for (int j = 0; j < i; ++j) {
            qi.push(max(double(0.),dist(seq[i], seq[j]) - rs[j]));
        }
        double r = qi.top();
        rs.push_back(r);
        ret += double(r) * double(r) * M_PI;
    }
    return ret;
}
vector<int> getNext(vector<int> seq) {
    if (seq.size() == 1) return vector<int>();
    int j = seq.size() - 1;
    while (j >= 1 && seq[j-1] > seq[j]) {
        j--;
    }
    if (j == 0 && seq[0] > seq[1])
        return vector<int>();
    int i = seq.size() - 1;
    while (seq[i] < seq[j-1]) i--;
    swap(seq[j-1], seq[i]);
    for (int i = j; i < j - 1 + seq.size()  - i; ++i) {
        swap(seq[i], seq[j - 1 + seq.size()  - i]);
    }
    return seq;
}
int main() {
    scanf("%d", &n);
    scanf("%lf%lf%lf%lf", &a0, &a1, &a2, &a3);
    x0 = min(a0, a2);
    x1 = max(a0, a2) - x0;
    y_0 = min(a1, a3);
    y_1 = max(a1, a3) - y_0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &a[i][0], &a[i][1]);
        a[i][0] -= x0;
        a[i][1] -= y_0;
    }
    for (int i = 0; i < n; ++i) {
        seq.push_back(i);
    }
    double ans = 0;
    while (true) {
        ans = max(ans, getArea(seq));
        seq = getNext(seq);
        if (seq.size() == 0) break;
    }
    printf("%.0lf\n", x1 * y_1 - ans);
}
