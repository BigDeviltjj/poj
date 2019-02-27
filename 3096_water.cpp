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
using namespace std;
void check(string& str) {
	for (int interval = 1; interval < str.length(); ++interval) {
		map<string, bool> Map;
		for (int i = 0; i < str.length() - interval; ++i) {
			string tmp;
			if (i + interval < str.length())
				tmp = str.substr(i, 1) + str.substr(i + interval, 1);
			if (Map.find(tmp) != Map.end()) {
				cout << str << " is NOT surprising." << endl;
				return;
			}
			else {
				Map[tmp] = true;
			}
		}
	}
	cout << str << " is surprising." << endl;

}
int main() {
	string str;
	while (true) {
		cin >> str;
		if (str == "*") break;
		check(str);

	}
	system("pause");
}
