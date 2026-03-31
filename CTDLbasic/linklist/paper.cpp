#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
//makenewnode
node *makenewnode(int x){
    node *newnode=new node;
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
//review
void review(node *head){
    if(head==NULL)return;
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
}
//size
int size(node *head){
    int dem=0;
    if(head==NULL)return;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
//pushfront
void pushfront(node *&head,int x){
    node *nodeA=makenewnode(x);
    nodeA->next=head;
    head=nodeA;
}
//pushback
void pushback(node *&head,int x){
    node *nodeB=makenewnode(x);
    if(head==NULL){
        head=nodeB;return;
    }
    node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
}
//insert
void insert(node *&head,int x,int k){
    int n=size(head);
    node *nodeC=makenewnode(x);
    if(k<1||k>n+1){
        cout<<"ERROR"<<endl;
        return;
    }
    if(k==1){
        pushfront(head,x);
        return;
    }
    node *tmp=head;
    for(int i=1;i<k-1;i++){
        tmp=tmp->next;
    }
    nodeC->next=tmp->next;
    tmp->next=nodeC;
}
//popfront
void popfront(node *&head){
    if(head==NULL)return;
    node *tmp=head;
    head=tmp->next;
    delete(tmp);
}
//popback
void popback(node *&head){
    if(head==NULL)return;
    node *tmp=head;
    if(tmp->next==NULL){
        delete tmp;
        head=NULL;
        return;
    }
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    node *last=tmp->next;
    tmp->next=NULL;
    delete(last);
}
//popmiddle
void popmiddle(node *&head,int k){
    int n=size(head);
    if(k<1||k>n){
        cout<<"ERROR"<<endl;
        return;
    }
    if(k==1){
        popfront(head);
        return;
    }
    node *tmp=head;
    for(int i=1;i<k-1;i++){
        tmp=tmp->next;
    }
    node* nodek=tmp->next;
    tmp->next=nodek->next;
    delete(nodek);
}
//cycle
void reverse(node *head){
    
}
//reverse
//mergesort
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
}