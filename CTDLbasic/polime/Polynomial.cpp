#include <bits/stdc++.h>
using namespace std;
struct Node{
    int coef;
    int expo;
    Node* next;
};
typedef struct Node* node;
node createnode(int coef,int expo){
    node newnode=new Node;
    newnode->coef=coef;
    newnode->expo=expo;
    newnode->next=NULL;
    return newnode;
}
void insert(node &head,int coef,int expo){
    if(coef==0)return;
    node newnode=createnode(coef,expo);
    if(head==NULL || head->expo<expo){
        newnode->next=head;
        head=newnode;
        return;
    }
    node tmp=head;
    while(tmp->next!=nullptr && tmp->next->expo>expo){
        tmp=tmp->next;
    }
    if(tmp->next!=nullptr && tmp->next->expo==expo){
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
void input(node &head){
    int n;
    cout<<"Nhập số hạng tử:";cin>>n;
    for(int i=0;i<n;i++){
        int coef,expo;
        cout<<"Nhập hệ số và mũ số:";cin>>coef>>expo;
        insert(head,coef,expo);
    }
}
void output(node head) {
    if(head==nullptr){
        cout<<"0\n";
        return;
    }
    bool first=true;
    while(head){
        int c=head->coef,e=head->expo;
        // In dau
        if (!first)cout<<(c>0?"+":"-");
        else if(c<0)cout<<"-";
        first=false;
        // In he so (dung abs de tranh in 2 lan dau -)
        int ac=abs(c);
        // In phan x^expo
        if(e==0)cout<<ac;//Hạng số c
        else if(e==1){if(ac!=1)cout<<ac;cout<<"x";}//3x hoac x
        else{if(ac!=1)cout<<ac;cout<<"x^"<<e;}//3x^2 hoac x^2
        head=head->next;
    }
    cout<<"\n";
}
node add(node p1,node p2){
    node res=nullptr;
    while(p1&&p2){
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
    while(p1!=nullptr){
        insert(res,p1->coef,p1->expo);
        p1=p1->next;
    }
    while(p2!=nullptr){
        insert(res,p2->coef,p2->expo);
        p2=p2->next;
    }
    return res;
}
//Convert dấu
node negatePolynomial(node p){
    node res=nullptr;
    while(p){
        insert(res,-p->coef,p->expo);
        p=p->next;
    }
    return res;
}
void freepoly(node &head){
    while(head){
        node tmp=head;
        head=head->next;
        delete(tmp);
    }
}
node subtract(node p1,node p2){
    node negp2= negatePolynomial(p2);
    node res=add(p1,negp2);
    freepoly(negp2);
    return res;
}
node Multiply(node p1,node p2){
    node res=nullptr;
    for(node i=p1;i!=nullptr;i=i->next){
        for(node j=p2;j!=nullptr;j=j->next){
            insert(res,i->coef*j->coef,i->expo+j->expo);
        }
    }
    return res;
}
int main(){
    node p1=nullptr;node p2=nullptr;
    cout<<"Nhập đa thức 1:"<<endl;
    input(p1);
    cout<<"Nhập đa thức 2:"<<endl;
    input(p2);
    while(1){
        cout<<"_______________OPTIONS_______________"<<endl;
        cout<<"1. In đa thức 1"<<endl;
        cout<<"2. In đa thức 2"<<endl;
        cout<<"3. Đổi dấu đa thức 1"<<endl;
        cout<<"4. Đổi dấu đa thức 2"<<endl;
        cout<<"5. Cộng 2 đa thức"<<endl;
        cout<<"6. Trừ 2 đa thức "<<endl;
        cout<<"7. Nhân 2 đa thức"<<endl;
        cout<<"0. STOP RUNNING PROGRAM"<<endl;
        cout<<"______________________________________"<<endl;
        int n;cout<<"NHẬP LỰA CHỌN:";cin>>n;
        if(n==1){
            output(p1);
        }
        else if(n==2){
            output(p2);
        }
        else if(n==3){
            p1=negatePolynomial(p1);
            output(p1);
        }
        else if(n==4){
            p2=negatePolynomial(p2);
            output(p2);
        }
        else if(n==5){
            node sum=add(p1,p2);
            cout<<"Sum 2 đa thức:";
            output(sum);
            freepoly(sum);
        }
        else if(n==6){
            node subtract1=subtract(p1,p2);
            cout<<"Subtract 2 đa thức:";
            output(subtract1);
            freepoly(subtract1);
        }
        else if(n==7){
            node multiply=Multiply(p1,p2);
            cout<<"Multiply 2 đa thức:";
            output(multiply);
            freepoly(multiply);
        }
        else if(n==0){
            break;
        }
    }
    return 0;
}