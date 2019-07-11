#include <iostream>
#include <assert.h>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

/*-----------------------qsort------------------*/

template<typename T>
T partition(T l, T r) {
    T k = l;
    typename T::value_type pivot = *r;
    for (T i = l; i != r; ++i) {
        if (*i < pivot) std::iter_swap(i, k++);
    }
    std::iter_swap(k, r);
    return k;
}

template<typename T>
void qsort(T l, T r) {
    if (l < r) {
        T k = partition(l, r);
        qsort(l, k-1);
        qsort(k+1, r);
    }
}

/*-----------------------power------------------*/
template<typename T>
T power(T x, int n) {
        T result = 1;
        assert(n>=0);
        while (n) {
                if (n & 1) {
                        result *= x;
                }
                x = x*x;
                n >>= 1;
        }
        return result;
}

/*-----------------------lower_bound------------------*/
template<typename iterator, typename T>
iterator lower_bound(iterator l, iterator r, T val) {
        int len = int(r - l);
        while (len > 0) {
                iterator half = l + len/2;
                if (*half < val) {
                        l = half+1;
                        len = len - len/2 - 1;
                }
                else {
                        len = len >> 1;
                }
        }
        return l;
}

/*-----------------------upper_bound------------------*/
template<typename iterator, typename T>
iterator upper_bound(iterator l, iterator r, T val) {
        int len = int(r - l);
        while (len > 0) {
                iterator half = l + len/2;
                if (*half <= val) {
                        l = half+1;
                        len = len - len/2 - 1;
                }
                else {
                        len = len >> 1;
                }
        }
        return l;
}

int main() {
    vector<int> a{9, 2, 3, 5, 4, 10, 1, 7, 6, 8};
    qsort(a.begin(), a.end() - 1);
    std::for_each(a.begin(), a.end(), [](int i){cout<<i<<endl;});
}
