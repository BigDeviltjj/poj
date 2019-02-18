#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, S;
double V;
struct edge {
	edge(){}
	edge(int src_, int dst_, double R_, double C_):src(src_),dst(dst_), C(C_), R(R_){}
	int dst, src;
	double C, R;
};
edge e[201];
int nex[201], head[201], vis[201];
int pos = 0;
int const INF = 100000000;
double dis[201];
double get_val(double val, edge const &e) {
	if (e.C >= val) return -1;
	return 1. / ((val - e.C) * e.R);
}
void foo() {
	memset(dis, 0, sizeof(dis));
	dis[S] = V;
	int cnt = N - 1;
	while (cnt--) {
		for (int i = 0; i < pos; ++i) {
			if (dis[e[i].dst] < (dis[e[i].src] - e[i].C) * e[i].R) {
				dis[e[i].dst] = (dis[e[i].src] - e[i].C) * e[i].R;
			}
		}
	}
	for (int i = 0; i < pos; ++i) {
		if (dis[e[i].dst] < (dis[e[i].src] - e[i].C)*e[i].R) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main() {
	memset(nex, -1, sizeof(nex));
	memset(head, -1, sizeof(head));

	cin >> N >> M >> S >> V;
	for (int i = 0; i < M; ++i) {
		int A, B;
		double Rab, Cab, Rba, Cba;
		cin >> A >> B >> Rab >> Cab >> Rba >> Cba;
		e[pos] = edge(A, B, Rab, Cab);
		nex[pos] = head[A];
		head[A] = pos++;

		e[pos] = edge(B, A, Rba, Cba);
		nex[pos] = head[B];
		head[B] = pos++;
	}
	foo();
}
