#include<iostream>
#include<vector>
#include<deque>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point {
	int x, y;
	double lat;
};
double Left(Point const &x, Point const &y, Point const &z) {
	return (y.x - x.x) * (z.y - y.y) - (y.y - x.y) * (z.x - y.x);
}
double getAngle(Point const &x, Point const &y)
{
	if (y.x == x.x) return 3.1415926/2;
	return atan((y.y - x.y) / (y.x - x.x));
}
double dis(Point const &x, Point const &y) {
	return sqrt((y.x - x.x) * (y.x - x.x) + (y.y - x.y) * (y.y - x.y));
}
int main() {
	int N, L;
	cin >> N >> L;
	vector<Point> P(N);
	int min = 100000, min_idx = 0;
	for (int i = 0; i < N; ++i) {
		cin >> P[i].x >> P[i].y;
		if (P[i].y < min) {
			min = P[i].y;
			min_idx = i;
		}
	}
	deque<int> q;
	if (Left(P[0], P[1], P[2]) > 0) {
		q.push_back(2);
		q.push_back(0);
		q.push_back(1);
		q.push_back(2);

	}
	else {
		q.push_back(2);
		q.push_back(1);
		q.push_back(0);
		q.push_back(2);
	}
	for (int i = 3; i < N; ++i) {
		if  (Left(P[q[q.size() - 2]], P[q[q.size() - 1]], P[i]) >  0 && Left(P[q[0]], P[q[1]], P[i]) > 0)
		{
			continue;
		}
		while ( q.size() >= 3 && !(Left(P[q[q.size() - 2]], P[q[q.size() - 1]], P[i]) > 0)) q.pop_back();
		q.push_back(i);
		while (q.size() >= 3 && !(Left(P[q[0]], P[q[1]], P[i]) > 0)) q.pop_front();
		q.push_front(i);
	}
	double length = 0;
	for (int i = 0; i < q.size() - 1; ++i) {
		length += dis(P[q[i]], P[q[i + 1]]);
	}
	length += 2 * L * 3.1415926;
	cout << int(round(length)) << endl;
	system("pause");
}


