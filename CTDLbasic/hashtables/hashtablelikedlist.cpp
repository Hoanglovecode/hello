#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};
typedef struct Node* node;
struct hashtable{
    int capacity;
    node *table;
};
int hashfunction(int key,int capacity){
    return key%capacity;
}
hashtable* createhashtable(int capacity){
    hashtable* ht=new hashtable;
    ht->capacity=capacity;
    ht->table=new node[capacity];
    for(int i=0;i<capacity;i++){
        ht->table[i]=nullptr;
    }
    return ht;
}
void insert(hashtable*ht,int key){
    int index=hashfunction(key,ht->capacity);
    node newnode=new Node(key);
    newnode->next=ht->table[index];
    ht->table[index]=newnode;
}
bool search(hashtable* ht,int key){
    int index=hashfunction(key,ht->capacity);
    node cur=ht->table[index];
    while(cur){
        if(cur->data==key)
            return true;
        cur=cur->next;
    }
    return false;
}
void remove(hashtable* ht,int key){
    int index=hashfunction(key,ht->capacity);
    node cur=ht->table[index];
    node prev=nullptr;
    while(cur){
        if(cur->data==key){
            if(prev==nullptr)
                ht->table[index]=cur->next;
            else
                prev->next=cur->next;
            delete cur;
            return;
        }
        prev=cur;
        cur=cur->next;
    }
}
void printhashtable(hashtable* ht){
    for(int i=0;i<ht->capacity;i++){
        cout<<"["<<i<<"]:";
        node cur=ht->table[i];
        while(cur){
            cout<<cur->data<<"->";
            cur=cur->next;
        }
        cout<<"NULL\n";
    }
}
int main(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   hashtable* ht=createhashtable(10);
   insert(ht,15);
   insert(ht,25);
   insert(ht,35);
   insert(ht,12);
   printhashtable(ht);
   cout<<"\nSearch 25:"<<search(ht,25)<<endl;
   remove(ht,25);
   cout<<"\nAfter delete:\n";
   printhashtable(ht);
}