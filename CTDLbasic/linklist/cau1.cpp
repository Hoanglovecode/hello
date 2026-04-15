#include <bits/stdc++.h>
using namespace std;
struct Node{
    string mahang,tenhang;
    int soluong;
    double dongia;
    Node* next;
    Node* pre;
};
typedef struct Node* node;
node khoitao(){
    node header=new Node;
    header->next=header;
    header->pre=header;
    return header;
}
node createnode(string mahang,string tenhang,int soluong,double dongia){
    node newnode=new Node;
    newnode->mahang=mahang;
    newnode->tenhang=tenhang;
    newnode->soluong=soluong;
    newnode->dongia=dongia;
    newnode->next=nullptr;
    newnode->pre=nullptr;
    return newnode;
}
void pushback(node header,string mahang,string tenhang,int soluong,double dongia){
    node nodeB=createnode(mahang,tenhang,soluong,dongia);
    node tmp=header;
    while(tmp->next!=header){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
    nodeB->pre=tmp;
    nodeB->next=header;
    header->pre=nodeB;
}
void xoahang(node header,string s){
    node tmp=header->next;
    while(tmp!=header){
        if(tmp->mahang==s){
            node del=tmp;
            tmp->pre->next=tmp->next;
            tmp->next->pre=tmp->pre;
            tmp=tmp->next;
            delete(del);
        }
        else tmp=tmp->next;
    }
}
void nhapdanhsach(node header){
    int n;
    cout<<"Nhap so mat hang:";cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string ma,ten;
        int soluong;
        double dongia;
        cout<<"Nhap ma hang:";getline(cin,ma);
        cout<<"Nhap ten hang:";getline(cin,ten);
        cout<<"Nhap so luong:";cin>>soluong;
        cout<<"Nhap don gia:";cin>>dongia;
        cin.ignore();
        pushback(header,ma,ten,soluong,dongia);
    }
}
void indau(node header){
    node tmp=header->next;
    if(tmp==header){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    while(tmp!=header){
        cout<<tmp->mahang<<"|"
            <<tmp->tenhang<<"|"
            <<tmp->soluong<<"|"
            <<tmp->dongia<<endl;
        tmp=tmp->next;
    }
}
void incuoi(node header){
    node tmp=header->pre;
    if(tmp==header){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    while(tmp!=header){
        cout<<tmp->mahang<<"|"
            <<tmp->tenhang<<"|"
            <<tmp->soluong<<"|"
            <<tmp->dongia<<endl;
        tmp=tmp->pre;
    }
}
double tongtien(node header){
    node tmp=header->next;
    double tong=0;
    while(tmp!=header){
        tong+=(tmp->soluong*tmp->dongia);
        tmp=tmp->next;
    }
    return tong;
}
int main(){
    node header=khoitao();
    nhapdanhsach(header);
    cout<<"Danh sach in tu dau:"<<endl;
    indau(header);
    cout<<"Danh sach in tu cuoi:"<<endl;
    incuoi(header);
    cout<<"Tong thanh tien:"<<tongtien(header)<<endl;
    string ma;
    cout<<"Nhap ma can xoa:";
    getline(cin,ma);
    xoahang(header,ma);
    cout<<"Danh sach sau khi xoa:"<<endl;
    indau(header);
}