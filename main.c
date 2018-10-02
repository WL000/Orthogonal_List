//有向图存储--十字链表
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcBox
{
    int tailvex,headvex;//弧的尾和头
    struct ArcBox *hlink,*tlink;//指向同弧头，头弧尾的结点
} ArcBox; //弧结点

typedef struct VexNode
{
    char data;
    ArcBox *firstin,*firstout;//以该节点为弧头和弧尾的第一个弧结点
} VexNode; //顶点结点

typedef struct
{
    VexNode  xlist[MAX_VERTEX_NUM];//表头向量
    int vexnum,arcnum;//有向图的定点数，

} OLGraph; //十字链表

void Print_OLGraph(OLGraph G)
{
    //打印十字链表
    int i;
    ArcBox *p;
    for(i=0; i<G.vexnum; i++)
    {
        p=G.xlist[i].firstout;
        while(p!=NULL)
        {
            printf("%d->%d",p->tailvex,p->headvex);
            p=p->tlink;
        }
    }
}//打印算法不对
int  LocateVex(OLGraph G,char n)
{
    //查找顶点在顶点向量中的位置
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.xlist[i].data=n)
        {
            return i;
        }
    }
}
void Create_OLGraph(OLGraph G)
{
//采用头插法建立十字链表
    int i,j,a,b;
    char v1,v2;//弧头，弧尾
    ArcBox *p;
    printf("输入有向图的顶点数和边数：\n");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    printf("输入定点的值：\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.xlist[i].data);
        G.xlist[i].firstin=NULL;
        G.xlist[i].firstout=NULL;//初始化指针
    }
    printf("输入弧：\n");
    for(j=0; j<G.arcnum; j++)
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);//在顶点向量中找到弧头，弧尾位置
        p=(ArcBox *)malloc(sizeof(ArcBox));
        p->hlink=NULL;
        p->tlink=NULL;
        p->headvex=b;
        p->tailvex=a;//给弧头弧尾赋值
        p->hlink=G.xlist[b].firstin;
        p->tlink=G.xlist[a].firstout;   //注意p是地址所以要用‘->’
        G.xlist[a].firstout=p;
        G.xlist[b].firstin=p;  //头插法建立十字链表
    }
    Print_OLGraph(G);
}
int main()
{
    //测试函数
    OLGraph G;
    Create_OLGraph(G);//创建十字链表
}
