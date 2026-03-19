#include <bits/stdc++.h>
//LIFO(Last in first out)
using namespace std;
int a[100000],maxN=100000;
int n=0;
int size(){
    return n;
}
bool empty(){
    return n==0;
}
void push(int x){
    if(n==maxN)return;
    a[n]=x;n++;
}
void pop(){
    if(n==0)return;
    for(int i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    --n;
}
int top(){
    return a[0];
}