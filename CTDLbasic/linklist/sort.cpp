#include <bits/stdc++.h>
using namespace std;
struct Sinhvien{
    double gpa;
    string name;
    Sinhvien(){
    }
    Sinhvien(string ten,double diem){
        name=ten;
        gpa=diem;
    }
};
typedef struct Sinhvien sv;
struct node{
    sv data;
    node *next;
};
node *makenewnode(sv x){
    node *newnode=new node;
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void pushback(node *&head,sv x){
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
    if(head==NULL)cout<<"ERROR"<<endl;
    while(head){
        cout<<head->data.name<<" "<<fixed<<setprecision(2)<<head->data.gpa<<endl;
        head=head->next; 
    }
}
void sapxep(node *&head){
    for(node *i=head;i!=NULL;i=i->next){
        node *minnode=i;
        for(node *j=i->next;j!=NULL;j=j->next){
            if(minnode->data.gpa > j->data.gpa){
                minnode=j;
            }
            else if(minnode->data.gpa==j->data.gpa){
                if(minnode->data.name > j->data.name){
                    minnode=j;
                }
            }
        }
        sv tmp=minnode->data;
        minnode->data=i->data;
        i->data=tmp; 
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   node *head=NULL;
   Sinhvien s("hoang",3.877);
   Sinhvien v("trung",3.655);
   Sinhvien c("Khanh",3.7432);
   Sinhvien g("gin",3.877);
   Sinhvien e("anh",3.477);
   Sinhvien f("bao",3.477);
   pushback(head,s);
   pushback(head,v);
   pushback(head,c);
   pushback(head,e);
   pushback(head,f);
   pushback(head,g);
   duyet(head);
   cout<<endl;
   sapxep(head);
   duyet(head);
}