#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;	
struct Node {
	Node(){}
	Node(string str_, int step_):str(str_),step(step_){}
	string str;
	int step;
};
string src, dst;
map<string, bool> mp;
queue<Node> q;
int bfs(){
	src += '0';
	mp[src] = 1;
	q.push(Node(src, 0));

	while (!q.empty()) {
		Node s = q.front();
		q.pop();
		if (s.str.substr(0, 6) == dst) return s.step;
		int idx = s.str[6] - '0';
		string tmp;
		tmp = s.str;
		if (idx != 0) swap(tmp[0], tmp[idx]);
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}
		tmp = s.str;
		if (idx != 5) swap(tmp[5], tmp[idx]);
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}
		tmp = s.str;
		if (tmp[idx] != '9' && tmp[idx] != dst[idx]) tmp[idx]++;
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}

		tmp = s.str;
		if (tmp[idx] != '0' && tmp[idx] != dst[idx]) tmp[idx]--;
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}

		tmp = s.str;
		if (idx != 0 && (idx == 5 || tmp[idx] == dst[idx])) tmp[6]--;
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}

		tmp = s.str;
		if (idx != 5 && (idx == 0 || tmp[idx] == dst[idx])) tmp[6]++;
		if (!mp.count(tmp)) {
			q.push(Node(tmp, s.step + 1));
			mp[tmp] = 1;
		}


	}
	return 0;
}
int main() {
	cin >> src >> dst;
	printf("%d\n", bfs());
}
