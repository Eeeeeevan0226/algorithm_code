#include<bits/stdc++.h>
 
using namespace std;
 
const int N=1e6+5;
const int MAX=2147483647;
 
struct node{        //建图(链式向前星，二维矩阵会炸)，储存边
    int from;
    int to;
    int value;
    int next;
}edge[200005];
int head[N];        
 
int dis[N];        //记录每一个顶点的距离
int visited[N];    //记录是否访问过某一个顶点
 
int main()
{
    int n,m,s;
    int cnt=0;
    scanf("%d%d%d",&n,&m,&s);
 
    for(int i=1;i<=n;i++) dis[i]=MAX;    //距离初始化为无穷大
 
    memset(head,0,sizeof(head));         //这两行其实可以不要
    memset(visited,0,sizeof(visited));
 
    for(int i=1;i<=m;i++)    //建图，储存边
    {
        cnt++;
        scanf("%d%d%d",&edge[cnt].from,&edge[cnt].to,&edge[cnt].value);
        int from=edge[cnt].from;
        int to=edge[cnt].to;
        edge[cnt].next=head[from];
        head[from]=cnt;
    }
 
    int start=s;            //以s为起点
    dis[start]=0;           //起点到自己的距离为0
 
 
    while(visited[start]!=1)    //开始模拟查找过程
    {
        visited[start]=1;    //标记该起点，表示已访问过
 
        for(int i=head[start];i!=0;i=edge[i].next)    //读取与起点相连的边
        {
            if(dis[edge[i].to]>dis[start]+edge[i].value)    //算法的核心
                dis[edge[i].to]=dis[start]+edge[i].value;
        }
 
        int minn=MAX;            //每一次都寻找所有点中距离最小的点
        for(int i=1;i<=n;i++)
        {
            if(visited[i]!=1 && minn>dis[i])
            {
                minn=dis[i];
                start=i;        //以距离最小的点为新的起点，开始查找
            }
        }
 
    }
    for(int i=1;i<=n;i++)
    {
        if(i==n) printf("%d\n",dis[i]);
        else printf("%d ",dis[i]);
    }
} 
