// Create a linked list connected to its adjacent vertices.

#include<stdio.h>
#include<stdlib.h>
struct Next
{
	int data;
	struct Next* adjacent;
};
struct VertexList
{
	struct Next* add;
	int node;
	struct VertexList*next;
};
struct VertexList * head=NULL;
struct VertexList* createVertex(int item)
{
	struct VertexList* nw=(struct VertexList*)malloc(sizeof(struct VertexList));
	if(nw==NULL)
	  printf("\n No space provided.");
	else
	{
		nw->node=item;
		nw->add=NULL;
		nw->next=NULL;
	}
	return nw;
}
void getVertex(int item)
{
	struct VertexList* nw=createVertex(item);
	if(head==NULL)
	{
		head=nw;
		return;
	}
	else
	{
		struct VertexList* p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=nw;
		p=NULL;
	}	
}
struct Next* getEdgeNode(int y)
{
	struct Next* nw=(struct Next*)malloc(sizeof(struct Next));
	if(nw==NULL)
	{
		printf("\n No space provided.");
		return;
	}  
	nw->data=y;
	nw->adjacent=NULL;
	return nw;
}
void getEdge(int x,int y)
{
	struct VertexList* p=head;
	while(p->node!=x)
	{
		p=p->next;
	}
	if(p->add==NULL)
	{
		p->add=getEdgeNode(y);	
		printf("P %u  EDGE %d\n",p,p->add);
	}
	else
	{
		struct Next* q=p->add;
		while(q->adjacent!=NULL)
		{
		  	 q=q->adjacent;
		}
		q->adjacent=getEdgeNode(y);
		printf("P %u  EDGE %d\n",p,q->adjacent);
	}
}
void traverse()
{
	struct VertexList* p=head;
	while(p->next!=NULL)
	{
		printf("\n %d : ",p->node);
		struct Next*q=p->add;
		if (q!=NULL)
		{
			while(q->adjacent!=NULL)
			{
				printf("%d-> ",q->data);
				q=q->adjacent;
			}
 			printf("%d ",q->data);
 	    }
		p=p->next;
		
	}
	printf("\n %d : ",p->node);
	struct Next*q=p->add;
	while(q->adjacent!=NULL)
	{
		printf("%d-> ",q->data);
		q=q->adjacent;
	}
	printf("%d ",q->data);
	free(p);
}
void main()
{
	printf("Kindly enter the number of vertices  ");
	int v,e,x,y;
	scanf("%d",&v);
	int i=0,j;
	for(i;i<v;i++)
	   getVertex(i);
	printf("\nPlease enter the number of edges  ");
	scanf("%d",&e);
	for(j=1;j<=e;j++)
	{
		printf(" Enter the origin vertex of %d edge         ",j);
		scanf("%d",&x);
		printf(" Enter the destination vertex of %d edge    ",j);
		scanf("%d",&y);
		getEdge(x,y);
	}
	printf("\nGraph representation is as follows:");
	traverse();
}
