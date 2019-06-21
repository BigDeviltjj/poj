#include<stdio.h> 
#include<stdlib.h>  
#define Max 4000037  
int hash[Max],num[Max];  
//hash判断和的位置，num是和为s的个数 bool used[Max];            
bool used[Max];
//判断hash是否用过 
int n,M,k[7],p[7],cnt,mid;   
int locat(int s) 
{  
    int tmp=s; 
    while(tmp<0) 
    {
        tmp+=Max;  
    }
    while(tmp>=Max)  
    {
        tmp-=Max;  
    }
    while(used[tmp]&&hash[tmp]!=s)  
    {   
        tmp++;   
        if(tmp>=Max)  
        {
            tmp-=Max;  
        }
    } 
    return tmp;
}  

void in_sert(int s)
{  
    int pos=locat(s);  
    hash[pos]=s; 
    used[pos]=1; 
    num[pos]++; 
}   
void left_dfs(int d,int s)          //左边一半的值的和的可能 
{  
    if(d==mid)  
    {   
        in_sert(s);  
        return  ;
    }  
    for(int i=1;i<=M;i++)  
    { 
        int tmp=k[d];   
        if(i!=1&&tmp!=0)   
        {    
            for(int j=0;j<p[d];j++)   
            {
                tmp*=i;  
            }
        }   
        left_dfs(d+1,s+tmp); 
    }
}  

void right_dfs(int d,int s)        //右边所有和的可能如果左右相等，那么就加上这个和的所有可能 
{  
    if(d==n)  
    {   
        s=-s;  
        int pos=locat(s);  
        if(hash[pos]==s) 
        {
            cnt+=num[pos];
        }
        return ;  
    }  
    for(int i=1;i<=M;i++) 
    {   
        int tmp=k[d];  
        if(i!=1&&tmp!=0) 
        {  
            for(int j=0;j<p[d];j++)  
            {
                tmp*=i;  
            }
        }  
        right_dfs(d+1,s+tmp);  
    } 
}  
int main() 
{  
    int i,j;  
    scanf("%d",&n); 
    scanf("%d",&M);  
    for(i=0;i<n;i++)  
    {   
        scanf("%d%d",&k[i],&p[i]);  
    } 
    mid=n/2;  
    cnt=0; 
    left_dfs(0,0); 
    right_dfs(mid,0); 
    printf("%d\n",cnt); 
    return 0;
}
