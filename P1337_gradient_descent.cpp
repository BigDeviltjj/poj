#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int x[1001],y[1001],w[1001];
double ans_x, ans_y;
double et = 100000;
int main() {
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d",&x[i],&y[i],&w[i]);
        ans_x +=1. * x[i]/n;
        ans_y +=1. * y[i]/n;
    }
    if (n == 1){
        printf("%.3f %.3f\n", ans_x, ans_y);
        return 0;
    }
    while (true) {
        double next_x,next_y;
        double grad_x =0, grad_y = 0;
        for (int i = 0; i < n; ++i) {
            grad_x += w[i] * (ans_x - x[i])*pow((ans_x - x[i])*(ans_x - x[i]) + (ans_y - y[i]) * (ans_y - y[i]),-0.5);
            grad_y += w[i] * (ans_y - y[i])*pow((ans_x - x[i])*(ans_x - x[i]) + (ans_y - y[i]) * (ans_y - y[i]),-0.5);

        }
        grad_x *= et;
        grad_y *= et;
        if (abs(grad_x) < 0.00005 && abs(grad_y) < 0.00005) break;

        ans_x = ans_x - grad_x;
        ans_y = ans_y - grad_y;
        et *= 0.9;
    }
    printf("%.3f %.3f\n", ans_x, ans_y);

}
