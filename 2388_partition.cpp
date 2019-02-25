#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int partition(int *a,int n, int middle) {
	int pivot = a[0];
	int i = 0, j = n - 1;
	while (i < j) {
		while (a[j] > pivot && i < j) {
			j--;
		}

		while (a[i]<=pivot && i<j)
		{
			++i;
		}
		if (i != j)
		{
			swap(a[i], a[j]);
		}
	}
	swap(a[0], a[j]);
	if (j == middle) return a[j];
	else
	{
		return j < middle ? partition(a + j + 1, n - j - 1, middle - j - 1) : partition(a, j, middle);
	}
}
int main() {
	int n;
	int a[10001];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &a[i]);
	}
	printf("%d\n",partition(a,n,n/2));
	system("pause");
	std::nth_element(a, a + n, a + 5);

} 
