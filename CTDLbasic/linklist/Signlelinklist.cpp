#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
typedef struct node node;
//How to creat new note
node *makenewnode(int x){
    node *newnode=new node;
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
//How to duyet node
void duyet(node *head){
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;//Lấy giá trị node tiếp gán vào địa chỉ head hiện tại
    }
}
//How to count node
int count(node*head){//size trong stack/queue
    int dem=0;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
//How to insert or add node vào đầu
//option 1
void pushfront(node **stack,int x){
    node *newnode=makenewnode(x);//creat node mới bằng hàm makenewnode
    //Phần next của node mới là giá trị của head
    newnode->next=*stack;//*head là địa chỉ của node trong dslk,là toán tử giải tham chiếu
    //Cập nhập node head = newnode
    *stack = newnode;
}
//option 2
void pushfront2(node*&head,int x){
    node *newnode=makenewnode(x);
    newnode->next=head;
    head=newnode;
}
//How to add node vào cuối
//option 1
void pushback(node**queue,int x){//push trong queue
    node *newnode=makenewnode(x);
    if(*queue==NULL){
        *queue=newnode;return ;
    }
    node *temp=*queue;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
//option2
void pushback2(node *&head,int x){
    node *nodeB=makenewnode(x);
    if(head==NULL){
        head=nodeB;return ;
    }
    node *tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
}
//How to insert
void insert(node *&head,int k,int x){
    int n=count(head);
    if(k<1||k>n+1){
        cout<<"Invalid Insert!"<<endl;
        return;
    }
    if(k==1){
        pushfront2(head,x);
        return;
    }
    node *newnode=makenewnode(x);
    node*tmp=head;
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;
    }
    newnode->next=tmp->next;
    tmp->next=newnode;
}
//How to popfront
//option 1
void popfront2(node **stack){//pop trong stack/queue
    if(*stack==NULL)return ;
    node *tmp=*stack;
    *stack=tmp->next;
    delete tmp;
}
//option 2
void popfront(node *&head){//pop trong stack
    if(head==NULL)return ;
    node *tmp=head;
    head=tmp->next;
    delete tmp;
}
//How to popback
void popback(node *&head){
    if(head==NULL)return;
    node *tmp=head;
    if(tmp->next==NULL){
        delete tmp;
        head=NULL;
        return;
    }
    while(tmp->next->next!=NULL){//node adjacent last node
        tmp=tmp->next;
    }
    node *last=tmp->next;
    tmp->next=NULL;
    delete last;
}
//How to popmiddle
void popmiddle(node *& head,int k){
    int n=count(head);
    if(k<1||k>n){
        cout<<"Invalid popmiddle!"<<endl;
        return;
    }
    if(k==1){
        popfront(head);return;
    }
    node *tmp=head;
    for(int i=1;i<=k-2;i++){
        tmp=tmp->next;//when tmp=node[k-1] => break
    }
    node *nodek=tmp->next;//node[k]
    tmp->next=nodek->next;
    delete nodek;
}

int top(node *head){
    if(head==NULL){
        cout<<"List empty\n";
        return -1;
    }
    return head->data;
}
bool empty(node *head){
    return head==NULL;
}
void reverse(node *&head){
    node*pre=NULL;
    node*cur=head;
    while(cur){
        node *tmp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    head=pre;
}
int main(){
    node *head=NULL;
    while(1){
        cout<<"--------------------------------------------------------\n";
        cout<<"1.Pushfront Node\n";
        cout<<"2.Pushback Node\n";
        cout<<"3.PushMiddle Node\n";
        cout<<"4.Count Node\n";
        cout<<"5.Review Node\n";
        cout<<"6.Popfront Node\n";
        cout<<"7.PopMiddle Node\n";
        cout<<"8.Popback Node\n";
        cout<<"9.Print First Value Node\n";
        cout<<"10.Reverse Node\n";
        cout<<"11.Enter '0' if you want to stop\n";
        cout<<"--------------------------------------------------------\n";
        int n;
        cout<<"Enter option: ";cin>>n;
        if(n==0){
            break;
        }
        else if(n==1){
            int i;cout<<"Enter address(value) node: ";cin>>i;
            pushfront2(head,i);
        }
        else if(n==2){
            int i;cout<<"Enter address node: ";cin>>i;
            pushback2(head,i);
        }
        else if(n==3){
            int i;cout<<"Enter address(value) node: ";cin>>i;
            int k;cout<<"What place do you want to insert? : ";cin>>k;
            insert(head,k,i);
        }
        else if(n==4){
            cout<<"You have "<<count(head)<<" Node recently"<<endl;
        }
        else if(n==5){
            duyet(head);
            cout<<endl;
        }
        else if(n==6){
            popfront(head);
        }
        else if(n==7){
            int k;cout<<"What place do you want to delete? : ";cin>>k;
            popmiddle(head,k);
        }
        else if(n==8){
            popback(head);
        }
        else if(n==9){
            cout<<top(head)<<endl;
        }
        else if(n==10){
            reverse(head);
            duyet(head);
            cout<<endl;
        }
        else{
            cout<<"Please enter again your option: ";
        }
    }
}