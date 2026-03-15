#include <bits/stdc++.h>
#define False 0;
#define True 1;
using namespace std;
struct ElementType{
    int id;
    string *name;
};
struct Listinfo{
    struct ElementType*array;
    unsigned int count;
    unsigned int capacity;
};
typedef struct Listinfo *List;
typedef int Position;
List create(unsigned capacity){
    List L=new Listinfo;
    if(L==NULL)return NULL;
    L->capacity=capacity;
    L->count=0;
    L->array=new ElementType();
    if(L->array==NULL)return NULL;
    return L;
}

int Insert(List L, struct ElementType e, Position p)
{
    Position current;
    if (p > L->count || L->count == L->capacity)
        return 0;
    current = L->count;
    while (current != p)
    {
        L->array[current] = L->array[current - 1];
        current--;
    }
    L->array[current] = e;
    L->count++;
    return 1;
}
int main(){
   freopen("output.txt","w",stdout);
   List CTDL12=create(50);
   struct ElementType std1;
   struct ElementType std2;
   struct ElementType std3;
   std1.id=1;std1.name="Le Van A";
   std2.id=1;std1.name="Le Van B";
   std3.id=1;std1.name="Le Van C";
    Insert(CTDL12,std1,0);
    Insert(CTDL12,std2,1);
    Insert(CTDL12,std3,2);
    //Tiếp theo nên làm gì?
    //In ra thông tin của các phần tử trong danh sách đã tạo
    for(int i=0;i<CTDL12->count;i++){
        cout<<"ID: "<<CTDL12->array[i].id<<" Name: "<<CTDL12->array[i].name<<endl;
    }
    // Cách Để in ra thông tin của các phần tử trong danh sách



}