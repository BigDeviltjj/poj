#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct Edge {
    Edge(){}
    Edge(int u_, int v_, int nex_):u(u_),v(v_),nex(nex_){}
    int u,v,nex;
};
Edge e[400005];
int head[400005], father[400005],n,m,k,star[400005],cnt;
bool broken[400005];
int ans[400005];
void addedge(int u, int v){
    e[cnt] = Edge(u,v,head[u]);
    head[u] = cnt++;
}
int get_father(int u) {
    if (father[u] == u) {
        return u;
    }
    else{
        return father[u] = get_father(father[u]);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n;++i){
        head[i] = -1;
        father[i] = i;
    }
    for (int i = 0; i < m;++i){
        int x,y;
        scanf("%d %d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    scanf("%d",&k);
    for (int i = 0; i < k;++i){
        scanf("%d",&star[i]);
        broken[star[i]] = 1;
    }
    int total = n - k;
    for (int i = 0; i < 2 * m;++i) {
        int u = e[i].u, v = e[i].v;
        if (!broken[u] && !broken[v] && get_father(u) != get_father(v)){
            total--;
            father[get_father(u)] = get_father(v);
        }
    }
    ans[k]=total;//当前就是最后一次破坏后的个数
    for (int i = k-1;i>=0;--i)
    {
        int u = star[i];
        total++;//修复一个点 联通体+1
        broken[u]=0;//修复
        for(int j=head[u];j!=-1;j=e[j].nex)//枚举每一个子点
        {
            int v = e[j].v;
            if(!broken[v] && get_father(u)!=get_father(v))
            {
                total--;//连一边减一个联通块
                father[get_father(u)] = get_father(v);
            }
        }
        ans[i]=total;
    }
    for (int i = 0;i<=k;i++) printf("%d\n",ans[i]);
    return 0;

}
