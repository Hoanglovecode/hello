#include <bits/stdc++.h>
using namespace std;
struct Node{
    int heSo;
    int soMu;
    Node * next;
};
typedef struct Node* node;
node createnode(int heSo,int soMu){
    node newnode= new Node;
    newnode->heSo=heSo;
    newnode->soMu=soMu;
    newnode->next=nullptr;
    return newnode;
} 
node createList(){
    node header=new Node;
    header->next=nullptr;
    return header;
}
void insert(node &header,int heSo,int soMu){
    if(heSo==0) return;
    node newnode=createnode(heSo,soMu);
    node head=header->next;
    if(head && head->soMu==soMu){
        head->heSo+=heSo;
        if(head->heSo==0){
            header->next=head->next;
            delete(head);
        }
        delete(newnode);
        return;
    }
    if(head==nullptr || head->soMu<soMu){
        newnode->next=head;
        header->next=newnode;
        return;
    }
    node tmp=head;
    while(tmp->next && tmp->next->soMu>soMu){
        tmp=tmp->next;
    }
    if(tmp->next && tmp->next->soMu==soMu){
        tmp->next->heSo+=heSo;
        if(tmp->next->heSo==0){
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
node tong(node a,node b){
    node res=createList();
    node p1=a->next;
    node p2=b->next;
    while(p1&&p2){
        if(p1->soMu>p2->soMu){
            insert(res,p1->heSo,p1->soMu);
            p1=p1->next;
        }
        else if(p1->soMu<p2->soMu){
            insert(res,p2->heSo,p2->soMu);
            p2=p2->next;
        }
        else{
            insert(res,p1->heSo+p2->heSo,p1->soMu);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1){
        insert(res,p1->heSo,p1->soMu);
        p1=p1->next;
    }
    while(p2){
        insert(res,p2->heSo,p2->soMu);
        p2=p2->next;
    }
    return res;
}
node tich(node p1,node p2){
    node res=createList();
    for(node i=p1->next;i!=nullptr;i=i->next){
        for(node j=p2->next;j!=nullptr;j=j->next){
            insert(res,i->heSo*j->heSo,i->soMu+j->soMu);
        }
    }
    return res;
}
void nhap(node &header){
    int n;cout<<"Nhap so hang tu:";cin>>n;
    for(int i=1;i<=n;i++){
        int heSo,soMu;
        cout<<"Nhap he so va so mu:";
        cin>>heSo>>soMu;
        insert(header,heSo,soMu);
    }
}
void xuat(node header){
    node head=header->next;
    if(head==nullptr){
        cout<<"\n0";
        return;
    }
    bool first=true;
    while(head){
        int c=head->heSo,e=head->soMu;
        if(first==false)cout<<(c>0?"+":"-");
        else{
            if(c<0)cout<<"-";
        }
        first=false;
        int ac=abs(c);
        if(e==0){
            cout<<ac;
        }
        else if(e==1){
            if(ac!=1)cout<<ac;
            cout<<'x';
        }
        else{
            if(ac!=1)cout<<ac;
            cout<<"x^"<<e;
        }
        head=head->next;
    }
    cout<<endl;
}
int main(){   
    node p1=createList();node p2=createList();
    cout<<"Nhap da thuc 1:\n";
    nhap(p1);
    cout<<"Nhap da thuc 2:\n";
    nhap(p2);
    cout<<"In da thuc 1:\n";
    xuat(p1);
    cout<<"In da thuc 2:\n";
    xuat(p2);
    node sum=tong(p1,p2);
    cout<<"Tong hai da thuc:";
    xuat(sum);
    node multiply=tich(p1,p2);
    cout<<"Tich hai da thuc:";
    xuat(multiply);
}