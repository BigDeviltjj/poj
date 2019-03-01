#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
char str[1000010];
int kmp[1000010],idx;
int main(){
	while (scanf("%d", &N) && N != 0) {
		getchar();
		for (int i = 0; i < N; ++i) {
			scanf("%c", &str[i]);
		}
		memset(kmp, 0, sizeof(kmp));
		int j = -1, i = 0;
		kmp[0] = -1;
		while (i <= N - 1) {
			if (j == -1 || str[i] == str[j]) {
				++j,++i;

				kmp[i] = j;
			}
			else
			{
				j = kmp[j];
			}
		}
		printf("Test case #%d\n", ++idx);

		for (int i = 2; i <= N; ++i) {
			int k = 0, v = kmp[i];
			if (v > 0 && i % (i - v) == 0)
				printf("%d %d\n", i, i / (i - v));
		}
		printf("\n");
	}
	
}
