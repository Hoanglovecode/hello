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
int count(node*head){
    int dem=0;
    while(head!=NULL){
        dem++;
        head=head->next;
    }
    return dem;
}
//How to insert or add node vào đầu
//option 1
void pushfront(node **head,int x){
    node *newnode=makenewnode(x);//creat node mới bằng hàm makenewnode
    //Phần next của node mới là giá trị của head
    newnode->next=*head;//*head là địa chỉ của node trong dslk,là toán tử giải tham chiếu
    //Cập nhập node head = newnode
    *head = newnode;
}
//option 2
void pushfront2(node*&head,int x){
    node *newnode=makenewnode(x);
    newnode->next=head;
    head=newnode;
}
//How to add node vào cuối
//option 1
void pushback(node**head,int x){
    node *newnode=makenewnode(x);
    if(*head==NULL){
        *head=newnode;return ;
    }
    node *temp=*head;
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
int main(){
    freopen("output.txt","w",stdout);
    node *head=new node;
    head->data=1;
    head->next=NULL;
    cout<<"Gia tri cua head la:"<<head<<endl;
    cout<<"Giu lieu ma head node quan ly la:"<<head->data<<endl;
    cout<<"Dia chi cua node tiep theo sau head la:"<<head->next<<endl;
    node *head2=NULL;
    for(int i=1;i<6;i++){
        pushfront(&head2,i);
    }
    for(int i=6;i<11;i++){
        pushfront2(head2,i);
    }
    cout<<"Danh sach sau khi them cac phan tu vao dau:"<<endl;
    duyet(head2);
    cout<<"\nSo luong node trong danh sach la:"<<count(head2)<<endl;
    node *head4=NULL;
    for(int i=0;i<13;i++){
        pushback2(head4,i);
    }
    duyet(head4);
}