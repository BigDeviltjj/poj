#include<iostream>
#include<cstdio>
#include<string.h>
int a[100][100], val[100][100], dir[4][2] = {0,1 ,0,-1,1,0,-1,0};
int R,C;
using namespace std;
bool valid(int x, int y, int k){
    if (!(x + dir[k][0] >= 0 && x + dir[k][0] < R)) return false;
    if (!(y + dir[k][1] >= 0 && y + dir[k][1] < C)) return false;
    if (a[x + dir[k][0]][y + dir[k][1]] >= a[x][y]) return false;
    return true;
}
        
void dfs(int i, int j){
    cout<<i<<" "<<j<<endl;
    if (!val[i][j]) return;
    int max = 1;
    for (int k = 0;k<4;++k){
        if (valid(i,j,k)){
            dfs(i + dir[k][0], j + dir[k][1]);
            int ret = 1 + val[i + dir[k][0]][j + dir[k][1]];
            if (ret > max) max =ret;
        }
    }
    val[i][j] = max;
}

int main(){
    cin>>R>>C;
    for (int i=0; i < R;++i)
        for (int j = 0; j < C;++j)
            cin>>a[i][j];

    memset(val, 0, sizeof(val));
    int max = -1;
    for (int i=0; i < R;++i)
        for (int j = 0; j < C;++j){
            dfs(i,j);
            if (val[i][j] > max) max = val[i][j];
        }
    cout<<max<<endl;
}


