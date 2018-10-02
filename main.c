//����ͼ�洢--ʮ������
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcBox
{
    int tailvex,headvex;//����β��ͷ
    struct ArcBox *hlink,*tlink;//ָ��ͬ��ͷ��ͷ��β�Ľ��
} ArcBox; //�����

typedef struct VexNode
{
    char data;
    ArcBox *firstin,*firstout;//�Ըýڵ�Ϊ��ͷ�ͻ�β�ĵ�һ�������
} VexNode; //������

typedef struct
{
    VexNode  xlist[MAX_VERTEX_NUM];//��ͷ����
    int vexnum,arcnum;//����ͼ�Ķ�������

} OLGraph; //ʮ������

void Print_OLGraph(OLGraph G)
{
    //��ӡʮ������
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
}//��ӡ�㷨����
int  LocateVex(OLGraph G,char n)
{
    //���Ҷ����ڶ��������е�λ��
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
//����ͷ�巨����ʮ������
    int i,j,a,b;
    char v1,v2;//��ͷ����β
    ArcBox *p;
    printf("��������ͼ�Ķ������ͱ�����\n");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    printf("���붨���ֵ��\n");
    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.xlist[i].data);
        G.xlist[i].firstin=NULL;
        G.xlist[i].firstout=NULL;//��ʼ��ָ��
    }
    printf("���뻡��\n");
    for(j=0; j<G.arcnum; j++)
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        a=LocateVex(G,v1);
        b=LocateVex(G,v2);//�ڶ����������ҵ���ͷ����βλ��
        p=(ArcBox *)malloc(sizeof(ArcBox));
        p->hlink=NULL;
        p->tlink=NULL;
        p->headvex=b;
        p->tailvex=a;//����ͷ��β��ֵ
        p->hlink=G.xlist[b].firstin;
        p->tlink=G.xlist[a].firstout;   //ע��p�ǵ�ַ����Ҫ�á�->��
        G.xlist[a].firstout=p;
        G.xlist[b].firstin=p;  //ͷ�巨����ʮ������
    }
    Print_OLGraph(G);
}
int main()
{
    //���Ժ���
    OLGraph G;
    Create_OLGraph(G);//����ʮ������
}
