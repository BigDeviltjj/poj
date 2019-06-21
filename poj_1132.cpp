#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int cnt=1;
    while (n--) {
        int i,j;
        char c;
        vector<string> map(32, string(32, '.'));
        scanf("%d %d", &i, &j);
        getchar();
        printf("Bitmap #%d\n", cnt++);
        while (true) {
            scanf("%c", &c);
            if (c == '.') break;
            if (c == 'E') {
                map[i][j-1] = 'X';
                i++;
            }
            if (c == 'W') {
                map[i-1][j] = 'X';
                i--;
            }
            if (c == 'N') {
                map[i][j] = 'X';
                j++;
            }
            if (c == 'S') {
                map[i-1][j-1] = 'X';
                j--;
            }
        }
        for (int j = 31; j >= 0; --j) {
            for (int i = 0; i <= 31; ++i)
                cout<<map[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
}
