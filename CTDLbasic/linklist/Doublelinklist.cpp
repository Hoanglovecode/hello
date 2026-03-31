#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node* pre;
};
typedef struct node node;
//create
node *makenewnode(int x){
    node *newnode=new node;
    newnode->data=x;
    newnode->next=NULL;
    newnode->pre=NULL;
    return newnode;
}
//count
int count(node *head){
    int dem=0;
    while(head->next!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
//review
void review(node *head){
    while(head->next!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
}
//pushfront
void pushfront(node *&head,int x){
    node *nodeA=makenewnode(x);
    nodeA->next=head;
    if(head!=NULL){
        head->pre=nodeA;
    }
    head=nodeA;
}
//pushback
void pushback(node *&head,int x){
    node *nodeB=makenewnode(x);
    node *tmp=head;
    if(head==NULL){
        head=nodeB;return;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
    nodeB->pre=tmp;
}
//insert
void insert(node *&head,int x,int k){
    node *nodeC=makenewnode(x);
    node *tmp=head;
    int n=count(head);
    if(k<1||k>n)return;
    if(k==1){
        pushfront(head,x);
        return;
    }
    for(int i=1;i<=k-1;i++){
        tmp=tmp->next;
    }
    nodeC->next=tmp;
    tmp->pre->next=nodeC;
    nodeC->pre=tmp->pre;
    tmp->pre=nodeC;
}
//popfront
void popfront(node *&head,int x){
    if(head==NULL)return;
    node *tmp=head;
    head=head->next;
    if(head!=NULL){
        head->pre=NULL;
    }
    delete(tmp);
}
//popback
//popmiddle
//delete node have value=x
//Find max value node
//FInd min value node
int main(){
   freopen("output.txt","w",stdout); 
}
