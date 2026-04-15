#include <bits/stdc++.h>
using namespace std;
struct Node{
    int coef;
    int expo;
    Node* next;
};
typedef struct Node* node;
node createnode(int coef,int expo){
    node newnode= new Node;
    newnode->coef=coef;
    newnode->expo=expo;
    newnode->next=nullptr;
    return newnode;
}
void insert(node &head,int coef,int expo){
    if(coef==0)return;
    node newnode=createnode(coef,expo);
    if(head==nullptr || head->expo<expo){
        newnode->next=head;
        head=newnode;
        return;
    }
    node tmp=head;
    while(tmp->next && tmp->next->expo>expo){
        tmp=tmp->next;
    }
    if(tmp->next && tmp->next->expo==expo){
        tmp->next->coef+=coef;
        if(tmp->next->coef==0){
            node del=tmp->next;
            tmp->next=del->next;
            delete(del);
        }
        delete(newnode);
    }
    else{
        newnode->next=tmp->next;
        tmp->next=newnode;
    }
}
//input
void input(node &head){
    int n;cout<<"Nhap so hang tu:";cin>>n;
    for(int i=0;i<n;i++){
        int coef,expo;
        cout<<"Nhap he so va so mu:";
        cin>>coef>>expo;
        insert(head,coef,expo);
    }
}
//output
void output(node head){
    if(head==nullptr){
        cout<<"\n0";
        return;
    }
    while(head){
        cout<<head->coef<<"x^"<<head->expo;
        if(head->next)cout<<(head->next->expo>0?"+":"-");
        head=head->next;
    }
}
node add(node p1,node p2){
    node res=nullptr;
    while(p1 && p2){
        if(p1->expo>p2->expo){
            insert(res,p1->coef,p1->expo);
            p1=p1->next;
        }
        else if(p1->expo<p2->expo){
            insert(res,p2->coef,p2->expo);
            p2=p2->next;
        }
        else{
            insert(res,p1->coef+p2->coef,p1->expo);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1){
        insert(res,p1->coef,p1->expo);
        p1=p1->next;
    }
    while(p2){
        insert(res,p2->coef,p2->expo);
        p2=p2->next;
    }
    return res;
}
node nhan(node p1,node p2){
    node res=nullptr;
    for(node i=p1;i!=nullptr;i=i->next){
        for(node j=p2;j!=nullptr;j=j->next){
            insert(res,i->coef*j->coef,i->expo+j->expo);
        }
    }
    return res;
}
int main(){
}
