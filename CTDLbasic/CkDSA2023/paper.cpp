#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
typedef struct Node* node;
struct Hashtable{
    int capacity;
    node* table;
};
typedef struct Hashtable* hashtable;
hashtable createhashtable(int capacity){
    hashtable ht=new Hashtable;
    ht->capacity=capacity;
    ht->table=new node[capacity];
    for(int i=0;i<capacity;i++){
        ht->table[i]==nullptr;
    }
    return ht;
}
int hashfunction(int key,int capacity){
    return key %capacity;
}
//insert
void insert(hashtable ht,int key){
    int index=hashfunction(key,ht->capacity);
    node newnode=new Node(key);
    newnode->next=ht->table[index];
    ht->table[index]=newnode;
}
//remove
void remove(hashtable ht,int key){
    int index=hashfunction(key,ht->capacity);
    node pre=nullptr;
    node cur=ht->table[index];
    while(cur){
        if(cur->data==key){
            if(pre==nullptr){
                ht->table[index]=cur->next;
            }
            else{
                pre->next=cur->next;
            }
            delete cur;
            return;
        }
        pre=cur;
        cur=cur->next;
    }
}
//search
bool search(hashtable ht,int key){
    int index= hashfunction(key,ht->capacity);
    node cur=ht->table[index];
    while(cur){
        if(cur->data==key)return true;
        cur=cur->next;
    }
    return false;
}
void printhashtable(hashtable ht){
    for(int i=0;i<ht->capacity;i++){
        cout<<"["<<i<<"]";
        node cur=ht->table[i];
        while(cur){      
            cout<<cur->data<<"->"; 
            cur=cur->next;
        }
        cout<<"NULL\n";
    }
}
int main(){
   hashtable ht=createhashtable(10);
   insert(ht,15);
   insert(ht,25);
   insert(ht,35);
   insert(ht,45);
   insert(ht,12);
   printhashtable(ht);
   cout<<"Search 25:"<<search(ht,25)<<endl;
   remove(ht,25);
   cout<<"After delete 25:"<<endl;
   printhashtable(ht);
}