#include<iostream>
#include<malloc.h>
using namespace std;
int access_list(struct node *&head);
struct node {
    int info;
    struct node *link;
};
void swap(int *i,int *l) {
    int a;
    a=*i;
    *i=*l;
    *l=a;
}
struct node *insert_clist(struct node *&head,int x) {
    struct node *newnode,*last ;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->link = NULL;
    if(head==NULL) {
        head=newnode;
        last=newnode;
    }
    else {
        last = head;
        while( last->link != NULL )
        {
            last = last->link;
        }
        last->link = newnode;
    }
    return head;
}
void bbsort_index(struct node *&head) {

    node* curr = head;
    int count = 0;
    while(curr!=NULL)
    {
        count++;
        curr = curr->link;
    }
    for(int i = 0 ; i < count ; i++ )
    {
        node *temp, *swap1;
        swap1 = head;
        for(int j = 0 ; j < count-i-1 ; j++ )
        {
            if(swap1->info > swap1->link->info)
            {
                node *swap2 = swap1->link;
                swap1->link = swap2->link;
                swap2->link = swap1;
                if(swap1 == head)
                {
                    head = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->link = swap2;
                }
            }
           //  access_list(head);
            temp = swap1;
            swap1 = swap1->link;
        }
    }




}
void bbsort_info(struct node *head) {
    struct node *cur;
    int n=0;
    while(cur!=NULL) {
        n++;
        cur=cur->link;
    }
    for(int i=0; i<n; i++) {
        int temp;
        struct node *p=head,*q=p->link;
        while(q!=NULL) {
            if(p->info > q->info)
                swap(p->info,q->info);
            p=p->link;
            q=q->link;

        }

    }
}
void selectionsort_info(struct node *&head) {
    struct node *r=head,*p,*temp=head;
    while(r->link!=NULL) {
        p=r;
        while(p!=NULL) {
            if(temp->info > p->info) {
                temp=p;
            }
            p=p->link;
        }
        swap(temp->info,r->info);
        //access_list(head);
        r=r->link;
        temp=r;
    }

}
void insertionsort_info(struct node *&head) {
    struct node *q=head->link,*p;
    while(q!=NULL) {
        p=head;
        while(p != q ) {
            if(p->info > q->info )
                swap(p->info, q->info);
            p=p->link;
            //access_list(head);
        }
        q=q->link;

    }

}

int access_list(struct node *&head) {
    struct node *p;
    p=head;
    if(p==NULL)
        cout<<"Empty\n";
    else {
        while (p != NULL) {
            cout<<p->info<<" ";
            p = p->link;
        }
            cout<<endl;

    }
    return 0;
}
int main () {
    struct node *head=NULL;
    int x,del=0,in=0,cou=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        insert_clist(head,x);
    }
    cout<<"Bubble Sort Index"<<endl;
    bbsort_index(head);
    access_list(head);
    cout<<"Bubble Sort Info"<<endl;
    bbsort_info(head);
    access_list(head);
    cout<<"Selection Sort Sort "<<endl;
    selectionsort_info(head);
    access_list(head);
    cout<<"Insertion Sort Sort "<<endl;
    insertionsort_info(head);
    access_list(head);
    return 0;

}

