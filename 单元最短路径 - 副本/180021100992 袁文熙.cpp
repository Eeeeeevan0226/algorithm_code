#include<bits/stdc++.h>
 
using namespace std;
 
const int N=1e6+5;
const int MAX=2147483647;
 
struct node{        //��ͼ(��ʽ��ǰ�ǣ���ά�����ը)�������
    int from;
    int to;
    int value;
    int next;
}edge[200005];
int head[N];        
 
int dis[N];        //��¼ÿһ������ľ���
int visited[N];    //��¼�Ƿ���ʹ�ĳһ������
 
int main()
{
    int n,m,s;
    int cnt=0;
    scanf("%d%d%d",&n,&m,&s);
 
    for(int i=1;i<=n;i++) dis[i]=MAX;    //�����ʼ��Ϊ�����
 
    memset(head,0,sizeof(head));         //��������ʵ���Բ�Ҫ
    memset(visited,0,sizeof(visited));
 
    for(int i=1;i<=m;i++)    //��ͼ�������
    {
        cnt++;
        scanf("%d%d%d",&edge[cnt].from,&edge[cnt].to,&edge[cnt].value);
        int from=edge[cnt].from;
        int to=edge[cnt].to;
        edge[cnt].next=head[from];
        head[from]=cnt;
    }
 
    int start=s;            //��sΪ���
    dis[start]=0;           //��㵽�Լ��ľ���Ϊ0
 
 
    while(visited[start]!=1)    //��ʼģ����ҹ���
    {
        visited[start]=1;    //��Ǹ���㣬��ʾ�ѷ��ʹ�
 
        for(int i=head[start];i!=0;i=edge[i].next)    //��ȡ����������ı�
        {
            if(dis[edge[i].to]>dis[start]+edge[i].value)    //�㷨�ĺ���
                dis[edge[i].to]=dis[start]+edge[i].value;
        }
 
        int minn=MAX;            //ÿһ�ζ�Ѱ�����е��о�����С�ĵ�
        for(int i=1;i<=n;i++)
        {
            if(visited[i]!=1 && minn>dis[i])
            {
                minn=dis[i];
                start=i;        //�Ծ�����С�ĵ�Ϊ�µ���㣬��ʼ����
            }
        }
 
    }
    for(int i=1;i<=n;i++)
    {
        if(i==n) printf("%d\n",dis[i]);
        else printf("%d ",dis[i]);
    }
} 
