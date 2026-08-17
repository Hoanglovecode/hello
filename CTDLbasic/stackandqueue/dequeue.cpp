#include <bits/stdc++.h>
using namespace std;
typedef struct ElementType{
    int id;
    const char *name;
} Element;
struct QueueInfo{
    int capacity;      // kích thước tối đa
    int count;         // số phần tử hiện có
    int front;         // vị trí đầu hàng đợi
    int rear;          // vị trí cuối hàng đợi
    Element *theArray;
};
typedef QueueInfo* Queue;
// Khởi tạo queue
Queue create_queue(int capacity){
    Queue q = new QueueInfo;

    q->capacity = capacity;
    q->count = 0;

    q->front = 0;
    q->rear = capacity - 1;

    q->theArray = new Element[capacity];

    return q;
}
// Kiểm tra rỗng
bool isEmpty(Queue q){
    return q->count == 0;
}
// Kiểm tra đầy
bool isFull(Queue q){
    return q->count == q->capacity;
}
// Tăng chỉ số theo kiểu vòng tròn
int increase(int index, int capacity){
    return (index + 1) % capacity;
}
// Thêm phần tử vào queue
bool enqueue(Queue q, Element e){
    if(isFull(q))
        return false;
    q->rear = increase(q->rear, q->capacity);
    
    q->theArray[q->rear] = e;

    q->count++;

    return true;
}

// Lấy phần tử ra khỏi queue
Element dequeue(Queue q){
    Element e = q->theArray[q->front];

    q->front = increase(q->front, q->capacity);

    q->count--;

    return e;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    Element e1 = {1, "Nguyen Van A"};
    Element e2 = {2, "Nguyen Van B"};
    Element e3 = {3, "Nguyen Van C"};

    Queue q = create_queue(10);

    enqueue(q, e1);
    enqueue(q, e2);
    enqueue(q, e3);

    while(!isEmpty(q)){
        Element e = dequeue(q);

        cout << "ID: " << e.id
             << "  Name: " << e.name
             << endl;
    }

    return 0;
}