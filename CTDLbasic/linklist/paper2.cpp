#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next;
    node *pre;
};
typedef struct node* node;
node createnode(int x){
    node newnode=new node;
    newnode->val=x;
    newnode->next=NULL;
    newnode->pre=nullptr;
    return newnode;
}
int count(node head){
    int dem=0;
    while(head->next){
        dem++;
        head=head->next;
    }
    return dem;
}
//duyet
void duyet(node head){
    if(head==nullptr)return;
    while(head->next!=nullptr){
        cout<<head->val<<' ';
        head=head->next;
    }
}
//pushfront
void pushfront(node &head,int x){
    node nodeA=createnode(x);
    nodeA->next=head;
    if(head!=NULL){
        head->pre=nodeA;
    }
    head=nodeA;
}
//pushback
void pushback(node &head,int x){
    node nodeB=createnode(x);
    if(head==nullptr){
        head=nodeB;
        return;
    }
    node tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
    nodeB->pre=tmp;
}
//insert
void insert(node &head,int x,int k){
    int n=count(head);
    if(k<1||k>n+1)return;
    if(k==1){
        pushfront(head,x);
        return;
    }
    node nodeC=createnode(x);
    node tmp=head;
    for(int i=1;i<=k-1;i++){
        tmp=tmp->next;
    }
    nodeC->next=tmp;
    tmp->pre->next=nodeC;
    nodeC->pre=tmp->pre;
    tmp->pre=nodeC;
}
//popfront
void popfront(node &head){
    if(head==nullptr)return;
    node del=head;
    head=head->next;
    if(head)head->pre=NULL;
    delete(del);
}
//popback
void popback(node &head){
    if(head==nullptr)return;
    if(head->next==nullptr){
        delete(head);
        head=nullptr;
        return;
    }
    node tmp=head;
    while(tmp->next->next){
        tmp=tmp->next;
    }
    node del=tmp->next;
    tmp->next=NULL;
    delete(del);

}
//popmiddle
void popmiddle(node &head,int k){
    int n=count(head);
    if(k<1||k>n)return;
    if(k==1){
        popfront(head);
        return;
    }
    node tmp=head;
    for(int i=1;i<=k-1;i++){
        tmp=tmp->next;
    }
    node del=tmp;
    tmp->pre->next=tmp->next;
    if(tmp->next!=NULL){
        tmp->next->pre=tmp->pre;
    }
    delete(del);
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
}