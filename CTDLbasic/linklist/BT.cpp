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
void duyet(node *head){
    while(head!=NULL){
        cout<<head->data.msv<<" "<<head->data.ten;
        head=head->next;
    }
}
typedef struct node node;
int main(){
    node *head=NULL;
    lophoc a,b,c;
    a.msv=102250068;a.ten="van hoang";
    b.msv=123132123;b.ten="toaan";
    c.msv=234234233;c.ten="afaafaf";

}