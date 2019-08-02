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

/*-----------------------high resolution add------------------*/
void highResAdd(vector<int>& a, vector<int>& b, vector<int>& c) {
    int i = 0;
    int shi = 0;
    while (i < a.size() || i < b.size()) {
        int temp = (i >= a.size() ? 0 : a[i]) + (i >= b.size() ? 0 : b[i]) + shi;
        shi = temp / 10;
        if (i < c.size()) {
            c[i] = temp % 10;
        }
        else {
            c.push_back(temp % 10);
        }
        i++;
    }
    if (shi == 1) {
        c.push_back(1);
    }
}

/*-----------------------count one in binary representation------------------*/
int Count(int val)
{
    int num = 0;
    while(val)
    {
        val &= (val -1);
        ++num;
    }
    return num;
}
int main() {
    vector<int> a{9, 2, 3, 5, 4, 10, 1, 7, 6, 8};
    qsort(a.begin(), a.end() - 1);
    std::for_each(a.begin(), a.end(), [](int i){cout<<i<<endl;});
}
