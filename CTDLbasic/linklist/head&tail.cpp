#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct LIST{
    node *head;
    node *tail;
};
void duyet(LIST l){
    if(l.head == NULL){
        cout << "DSLK rong !\n";
    }
    else{
        node *tmp = l.head;
        while(tmp != NULL){
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
    }
}

void themcuoi(LIST &l, int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    if(l.head == NULL){
        l.head = newNode;
        l.tail = newNode;
    }
    else{
        l.tail->next = newNode;
        l.tail = newNode;
    }
}
int main(){
    LIST l;
    l.head = NULL; l.tail = NULL;
    for(int i = 1; i <= 10; i++){
        themcuoi(l, i);
    }
    duyet(l);
}