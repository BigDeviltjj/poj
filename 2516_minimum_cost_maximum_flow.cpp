#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
	Edge() {}
	Edge(int from_, int to_, int cap_, int flow_, int cost_) :from(from_), to(to_), cap(cap_), flow(flow_), cost(cost_) {}
	int from, to, cap, flow, cost;
};

int N,M,K;
int s, t;
int  sc[50][50], tc[50][50], cost[50][50],sum[200];
int past[102];
vector<Edge> e;
vector<int> p2e[105];
bool SPFA(int &flow, int &cost) {
	vector<int> dis(M + N + 2, INF);
	vector<int> a(M + N + 2, INF);
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	vector<bool> used(M + N + 2, 0);
	used[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		used[u] = false;
		for (int i = 0; i < p2e[u].size(); ++i) {
			int idx = p2e[u][i];
			int v = e[idx].to;
			if (dis[u] + e[idx].cost < dis[v] && e[idx].cap > e[idx].flow) {
				dis[v] = dis[u] + e[idx].cost;
				past[v] = idx;
				a[v] = min(e[idx].cap - e[idx].flow, a[u]);
				if (!used[v]) {
					q.push(v);
					used[v] = 1;
				}
			}
		}
	}
	if (dis[t] == INF) return false;
	cost = dis[t];
	flow = a[t];
	int u = t;
	while (u != s) {
		e[past[u]].flow += flow;
		e[past[u] ^ 1].flow -= flow;
		u = e[past[u]].from;
	}
	return true;
}
int MCMF(int &tot_flow) {
	int ret = 0,flow = 0, cost = 0;
	while (SPFA(flow, cost)) {
		ret += flow * cost;
		tot_flow += flow;
	}
	return ret;
}
int main() {
	
	while (scanf("%d %d %d", &N, &M, &K) == 3 && N) {
		e.clear();
		memset(sum, 0, sizeof(sum));
		memset(sc, 0, sizeof(sc));
		memset(tc, 0, sizeof(tc));
		memset(cost, 0, sizeof(cost));

		s = N + M;
		t = s + 1;

		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < K; ++j) {
				scanf("%d", &tc[i][j]);
				sum[j] += tc[i][j];

			}
		}
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < K; ++j) {
				scanf("%d", &sc[i][j]);
			}
		}
		int flag = 0;
		for (int k = 0; k < K; ++k) {
			e.clear();
			for (int i = 0; i < N + M + 2; ++i)
				p2e[i].clear();
			memset(past, -1, sizeof(past));

			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					scanf("%d", &cost[i][j]);
					e.push_back(Edge(j, i + M, INF, 0, cost[i][j]));
					p2e[j].push_back(e.size() - 1);
					e.push_back(Edge(i + M, j, 0, 0, -cost[i][j]));

					p2e[i + M].push_back(e.size() - 1);

				}
			}
			if (flag == 1) continue;

			for (int i = 0; i < M; ++i) {
				e.push_back(Edge(s, i, sc[i][k]	, 0, 0));
				p2e[s].push_back(e.size() - 1);
				e.push_back(Edge(i, s, 0, 0, 0));

				p2e[i].push_back(e.size() - 1);

			}
			for (int i = 0; i < N; ++i) {
				e.push_back(Edge(i+M, t, tc[i][k], 0, 0));
				p2e[i + M].push_back(e.size() - 1);
				e.push_back(Edge(t, i + M, 0, 0, 0));

				p2e[t].push_back(e.size() - 1);

			}
			int tot_flow = 0;
			ans += MCMF(tot_flow);
			if (tot_flow != sum[k]) flag = 1;
		}
		if (flag) printf("-1\n");
		else
			printf("%d\n", ans);
	}
}
