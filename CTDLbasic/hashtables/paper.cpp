#include <bits/stdc++.h>
using namespace std;

struct Element{
    int id;
    string name;
};

struct QueueInfo{
    int capacity;
    int count;
    int front;
    int rear;
    Element *a;
};

typedef QueueInfo* Queue;

Queue createQueue(int capacity){
    Queue q = new QueueInfo;

    q->capacity = capacity;
    q->count = 0;
    q->front = 0;
    q->rear = capacity - 1;

    q->a = new Element[capacity];

    return q;
}

bool empty(Queue q){
    return q->count == 0;
}

bool full(Queue q){
    return q->count == q->capacity;
}

int nextPos(int pos, int capacity){
    return (pos + 1) % capacity;
}

void push(Queue q, Element x){
    if(full(q)) return;

    q->rear = nextPos(q->rear, q->capacity);
    q->a[q->rear] = x;
    q->count++;
}

Element pop(Queue q){
    Element x = q->a[q->front];

    q->front = nextPos(q->front, q->capacity);
    q->count--;

    return x;
}

Element Front(Queue q){
    return q->a[q->front];
}

int main(){
    Queue q = createQueue(10);

    push(q, {1, "Nguyen Van A"});
    push(q, {2, "Nguyen Van B"});
    push(q, {3, "Nguyen Van C"});

    while(!empty(q)){
        Element x = pop(q);

        cout << x.id << " "
             << x.name << '\n';
    }

    return 0;
}