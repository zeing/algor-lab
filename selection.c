#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *Insert(struct node *list,int x)
{
    struct node *newnode,*p;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = NULL;
    if(list == NULL)
    {
        list = newnode;
    }
    else
    {
        p = list;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = newnode;
    }
    return list;
};

void Print(struct node *list)
{
    struct node *p;
    p = list;
    while( p!=NULL )
    {
        printf("%d ",p->info);
        p = p->link;
    }
}

void Selection(struct node *list)
{
    struct node *p,*q,*r;
    int temp;
    q = list;
    r = list;
    p = list->link;
    while( r->link!=NULL )
    {
        q = r;
        p = r->link;
        while( p != NULL )
        {
            if( p->info < q->info )
            {
                q = p;
            }
            p = p->link;
        }
        temp = q->info;
        q->info = r->info;
        r->info = temp;

        r = r->link;
    }
}

void main()
{
    struct node *list;
    list = NULL;
    int i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        list = Insert(list,x);
    }
    Selection(list);
    Print(list);
}
