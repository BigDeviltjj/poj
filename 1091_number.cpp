#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
long long factor[100] = {0};
long long number[100] = {0};
long long N, M;
int index = 0;
long long fast_pow(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) res *= a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
void dfs(long long idx, long long layer, long long prime) {
	if (layer >= index) return;
	number[layer] += fast_pow(((long long)(M / (factor[idx] * prime))), N);
	for (long long i = idx + 1; i < index; i++)
	{
		dfs(i, layer + 1, prime * factor[idx]);
	}
}
int main() {
	scanf("%lld %lld", &N, &M);
//            clock_t startTime,endTime;
            
//            startTime = clock();
            if (M == 0) {printf("%d\n",0); return 0;}
	    long long M1 = M;
	    factor[0] = 1;
            index = 1;
            for (int i =2 ; i * i <= M; ++i)
	    {
	    	if (M1 % i == 0) factor[index++] = i;
	    	while (M1 % i == 0) M1 /= i;
	    }
            if (M1 != 1) factor[index++] = M1;
	    dfs(0, 0, 1);
	    long long ret = 0;
	    for (size_t i = 0; i < index; ++i) {
                if (i %2 == 0)
	    	    ret += number[i];
                else 
                    ret -= number[i];
	    }
	    printf("%lld\n", ret);
}
