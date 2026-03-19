#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
//tao node
node *makenewnode(int x){
    node *newnode =new node;
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
//duyet node
void duyet(node *head){
    while(head->next!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
}
//dem node
int count(node*head){
    int dem=0;
    while(head->next!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
//them giua
void pushfront(node *&head,int x){
    node *nodeA=makenewnode(x);
    nodeA->next=head;
    head=nodeA;
}
//them cuoi
void pushback(node *&head,int x){
    node *nodeB=makenewnode(x);
    if(head=NULL){
        head=nodeB;return ;
    }
    node *tmp=nodeB;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
}