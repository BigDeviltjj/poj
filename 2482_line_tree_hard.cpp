#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sum[20010], val[20010];
struct Star
{
	Star(){}
	Star(int x_, int y_, int c_) :x(x_), y(y_), c(c_) {}
	int x, y, c;
	friend bool operator<(const Star& s1, const Star& s2)  {
		if (s1.x == s2.x) return s1.c < s2.c;
		else
			return s1.x < s2.x;
	}
};
void update(int ql, int qr, int v, int i, int l, int r) {
	if (ql <= l && qr >= r) {
		sum[i] += v;
		val[i] += v;
		return;
	}
	int m = (l + r) / 2;
	if (ql<=m) update(ql, qr, v, i * 2, l, m);
	if (qr>m) update(ql, qr, v, i * 2 + 1, m + 1, r);
	sum[i] = max(sum[i * 2 + 1], sum[i * 2]) + val[i];
}
int main() {
	int n, w, h,x,y,c;
	while (scanf("%d %d %d",&n,&w,&h)) {
		memset(sum, 0, sizeof(sum));
		memset(val, 0, sizeof(val));

		vector<Star> star;
		vector<int> Y;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y >> c;
			star.push_back(Star(x, y, c));
			star.push_back(Star(x + w, y, -c));
			Y.push_back(y);
			Y.push_back(y + h);
		}
		sort(star.begin(), star.end());
		sort(Y.begin(), Y.end());
		int y_cnt = unique(Y.begin(),Y.end()) - Y.begin();
		int ans;
		for (int i = 0;i < star.size();++i){
			int l = lower_bound(Y.begin(),Y.end(),star[i].y) - Y.begin();
			int r = lower_bound(Y.begin(), Y.end(), star[i].y + h) - Y.begin() - 1;
			update(l, r, star[i].c, 1, 0, y_cnt-1);
			ans = max(ans, sum[1]);
		}
		cout << ans << endl;
	}
}
