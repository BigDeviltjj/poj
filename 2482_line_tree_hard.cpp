#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int sum[80100], val[80100];
struct Star
{
	Star(){}
	Star(long long x_, long long y_, long long c_) :x(x_), y(y_), c(c_) {}
	long long x, y, c;
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
	int n;
        long long x,y,c, w,h;
	while (scanf("%d %ld %ld",&n,&w,&h) == 3) {

	        if(n==0)
	        {
	            printf("0\n");
	            continue;
	        }
		memset(sum, 0, sizeof(sum));
		memset(val, 0, sizeof(val));

		vector<Star> star;
		vector<long long> Y;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
                        scanf("%ld %ld %ld",&x, &y, &c);
			star.push_back(Star(x, y, c));
			star.push_back(Star(x + w, y, -c));
			Y.push_back(y);
			Y.push_back(y + h);
		}
		sort(star.begin(), star.end());
		sort(Y.begin(), Y.end());
		int y_cnt = unique(Y.begin(),Y.end()) - Y.begin();
		int ans = 0;
		for (int i = 0;i < star.size() - 1;++i){
			int l = lower_bound(Y.begin(),Y.begin() + y_cnt,star[i].y) - Y.begin();
			int r = lower_bound(Y.begin(), Y.begin() + y_cnt, star[i].y + h) - Y.begin() - 1;
			if (l <= r) update(l, r, star[i].c, 1, 0, y_cnt-1);
			ans = max(ans, sum[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
