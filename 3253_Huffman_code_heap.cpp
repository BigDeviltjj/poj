#define _CRT_SECURE_NO_WARNINGS
#define cal(x) (i##x * i##x * i##x  *x])
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;

int heap[20000];
int n;
int heap_num;
void Down(int i, int n) {
	while (i <= n) {
		if (i * 2 + 1 <= n) {
			if (heap[i * 2] <= heap[i * 2 + 1] && heap[i * 2] < heap[i]) {
				swap(heap[i], heap[i * 2]);
				i *= 2;
			}
			else
			{
				if (heap[i * 2 + 1] <= heap[i * 2] && heap[i * 2 + 1] < heap[i]) {
					swap(heap[i], heap[i * 2 + 1]);
					i = i * 2 + 1;
				}
				else break;
			}

		}
		else
			if (i * 2 <= n) {
				if (heap[i * 2] < heap[i]) {
					swap(heap[i], heap[i * 2]);
					i *= 2;
				}
				else break;
			}
			else break;
	}
}
int heap_pop() {
	int ans = heap[1];
	swap(heap[1], heap[heap_num]);
	Down(1, --heap_num);
	return ans;
}
void heap_push(int x) {
	heap[++heap_num] = x;
	int cur = heap_num;
	while (cur > 1 && heap[cur]< heap[cur/2]) {
		swap(heap[cur], heap[cur / 2]);
		cur /= 2;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int len;
		scanf("%d", &heap[i]);
	}
	for (int i = n / 2; i >= 1; --i) {
		Down(i,n);
	}
	heap_num = n;
	long long ans = 0;
	while (heap_num > 1) {
		int val1 = heap_pop();
		int val2 = heap_pop();
		ans += (long long)val1 + val2;
		heap_push(val1 + val2);
	}
	printf("%lld\n", ans);
	system("pause");
} 
