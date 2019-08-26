#include<iostream>
#include<malloc.h>
using namespace std;
struct node {
    int info;
    struct node *lson, *rson;
};
void insert_tree(struct node *&tree, int x) {
    struct node *p=tree,*q=tree,*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info=x;
    newnode->lson=NULL,newnode->rson=NULL;
    if(tree==NULL) {
        tree=newnode;
    } else {
        while(p!=NULL) {
            if(x < p->info) {
                p=p->lson;
             //   cout<<"lson"<<x<<" "<<endl;
            } else {
                p=p->rson;
              //  cout<<"rson"<<x<<" "<<endl;
            }
            if(p!=NULL)
                q=p;
        }
        if(x < q->info) q->lson=newnode;
        else q->rson=newnode;
    }
}
void preorder(struct node *&tree) {
    if(tree != NULL) {
        preorder(tree->lson);
        cout<<tree->info<<" ";
        preorder(tree->rson);
    }
}
void inorder(struct node *&tree) {
    if(tree != NULL) {
        cout<<tree->info<<" ";
        inorder(tree->lson);
        inorder(tree->rson);
    }
}
void postorder(struct node *&tree) {
    if(tree != NULL) {
        postorder(tree->lson);
        postorder(tree->rson);
        cout<<tree->info<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    struct node *tree=NULL;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        insert_tree(tree, x);
    }
       preorder(tree);
       cout<<endl;
       inorder(tree);
       cout<<endl;
       postorder(tree);
 }
