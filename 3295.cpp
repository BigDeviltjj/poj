#include <iostream>
#include <string>
#include <deque>
#include <map>
using namespace std;
map<char, int> off;
void K(deque<bool> &v) {
	if (v[0] == 1 && v[1] == 1)
	{
		v.pop_front();
		v.pop_front();

		v.push_front(1);
	}
	else
	{
		v.pop_front();
		v.pop_front();

		v.push_front(0);
	}
}
void A(deque<bool> &v) {
	if (v[0] == 0 && v[1] == 0)
	{
		v.pop_front();
		v.pop_front();

		v.push_front(0);
	}
	else
	{
		v.pop_front();
		v.pop_front();

		v.push_front(1);
	}
}

void N(deque<bool> &v) {
	if (v[0] == 1)
	{
		v[0] = 0;
	}
	else
	{
		v[0] = 1;
	}
}
void C(deque<bool> &v) {
	if (v[0] == 1 && v[1] == 0)
	{
		v.pop_front();
		v.pop_front();

		v.push_front(0);
	}
	else
	{
		v.pop_front();
		v.pop_front();

		v.push_front(1);
	}
}
void E(deque<bool> &v) {
	if (v[0] == v[1])
	{
		v.pop_front();
		v.pop_front();

		v.push_front(1);
	}
	else
	{
		v.pop_front();
		v.pop_front();

		v.push_front(0);
	}
}
int main() {
	
	off['p'] = 0;
	off['q'] = 1;
	off['r'] = 2;
	off['s'] = 3;
	off['t'] = 4;
	string str;
	while (cin >> str) {
		if (str == "0") break;
		bool t = true;
		for (int v = 0; v < 32; ++v) {
			deque<bool> val;
			for (int i = str.size() - 1; i >= 0; --i) {
				if (str[i] >= 'a' && str[i] <= 'z') {
					val.push_front((1 << off[str[i]]) & v);
				}
				else {
					switch (str[i])
					{
					case 'K':K(val);
						break;
					case 'A':A(val);
						break;
					case 'N':N(val);
						break;
					case 'C':C(val);
						break;
					case 'E':E(val);
						break;
					default:
						break;
					}
				}
			}
			if (val[0] == 0) {
				t = false;
				break;
			}
		}
		if (t == true) cout << "tautology" << endl;
		else cout << "not" << endl;	
	}
}
