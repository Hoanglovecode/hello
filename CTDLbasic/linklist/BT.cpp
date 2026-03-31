#include <bits/stdc++.h>
using namespace std;
struct lophoc{
    int msv;
    string ten;
};
struct node{
    lophoc data;
    node *next;
};
node *makenewnode(lophoc x){
    node *newnode=new node;
    newnode->data =x; 
    newnode->next=NULL;
    return newnode;
}
void pushback(node *&head,lophoc x){
    node *newnode=makenewnode(x);
    if(head==NULL){
        head=newnode;
        return;
    }
    node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newnode;
}
void duyet(node *head){
    while(head!=NULL){
        cout<<head->data.msv<<" "<<head->data.ten<<"\n";
        head=head->next;
    }
}
int main(){
    node *head=NULL;
    lophoc a,b,c;
    a.msv=102250068;a.ten="van hoang";
    b.msv=123132123;b.ten="toaan";
    c.msv=234234233;c.ten="afaafaf";
    pushback(head,a);
    pushback(head,b);
    pushback(head,c);
    duyet(head);
}