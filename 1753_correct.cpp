#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
 
struct node{
    int state;
    int step;
};
 
bool vis[65536];
 
int change[16] = {
    //16种状态转换，对应4*4的翻子位置
    51200,58368,29184,12544,
    35968,20032,10016,4880,
    2248,1252,626,305,
    140,78,39,19
};
 
int bfs(int state){
    memset(vis,false,sizeof(vis));    //标记每一个状态都未访问过
    queue<node> q;
    node cur,next;
    cur.state = state;
    cur.step = 0;
    q.push(cur);
    vis[state] = true;
 
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.state == 0 || cur.state == 0xffff)   //65535
            return cur.step;
        for(int i = 0; i < 16; ++i){
            next.state = cur.state^change[i];
            next.step = cur.step + 1;
            if(vis[next.state])
                continue;
            if(next.state == 0 || next.state == 0xffff)   //65535
                return next.step;
            vis[next.state] = true;
            q.push(next);
        }
    }
    return -1;
}
 
int main(){
    int state,ans;
    char ch[5][5];
	for (int i = 0; i < 100; ++i ){
                printf("%d:",i);
	        ans = bfs(i);
        	if(ans == -1)
            		puts("Impossible");
        	else
            		printf("%d\n",ans);
        }
    return 0;
}
