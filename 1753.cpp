#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
bool chess[65536] = { false };
const int ans_w = 65535;
const int ans_b = 0;

int getRule1(int stat, int pos) {
	stat ^= 1 << pos;
	return stat;
}
int getRule2(int stat, int pos) {
	stat ^= 1 << pos;
	if (!(pos % 4 == 0)) 	stat ^= 1 << (pos - 1);
	if (pos>3) stat ^= 1 << (pos - 4);
	if (!((pos+1) % 4 == 0)) stat ^= 1 << (pos + 1);
	if (pos<=11) stat ^= 1 << (pos + 4);

	return stat;
}
int main() {
	int start_status = 0;
	for (int i = 0; i < 4; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 4; ++j) {
			start_status = (start_status << 1) + (tmp[j] == 'w' ? 1 : 0);
		}
	}
    for (int i = 0; i < 100;++i)
    {
        cout<<i<<":"<<endl;
        start_status = i;
        memset(chess, false, sizeof(chess));
	chess[start_status] = 1;
	queue<int> q;
	q.push(start_status);
	int step = 0;
        bool found_ans = false;
	if (start_status == ans_w || start_status == ans_b) {
		cout << 0 << endl;
                continue;
	}
	while (!q.empty()) {
		queue<int> tmp_q;
		step++;
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			for (int i = 0; i < 16; ++i) {
				int rule_1 = getRule1(curr, i), rule_2 = getRule2(curr, i);

				if (chess[rule_1] == false) {
					if (rule_1 == ans_w || rule_1 == ans_b) {
						cout << step << endl;
                                                found_ans = true;
                                                break;

					}
					tmp_q.push(rule_1);
					chess[rule_1] = 1;
				}
				if (chess[rule_2] == false) {
					if (rule_2 == ans_w || rule_2 == ans_b) {
						cout << step << endl;
                                                found_ans = true;
                                                break;

					}
					tmp_q.push(rule_2);
					chess[rule_2] = 1;
				}
			}
                        if (found_ans == true) break;
		}
                if (found_ans == true) break;
		q = tmp_q;
	}
        if (found_ans == true) continue;
	cout << "Impossible" << endl;
    }
	return 0;
}
