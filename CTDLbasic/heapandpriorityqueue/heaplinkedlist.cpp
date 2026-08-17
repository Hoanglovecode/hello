#include <bits/stdc++.h>
using namespace std;
struct heapsortinfo{
    int length;
    int heapsize;
    int* array;
};
typedef heapsortinfo* heapsort;
heapsort create(int a[],int capacity){
    heapsort newh= new heapsortinfo;
    newh->length=capacity;
    newh->heapsize=capacity;
    newh->array=new int[capacity];
    for(int i=0;i<capacity;i++){
        newh->array[i]=a[i];
    }
    return newh;
}
void maxheapify(heapsort h,int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<h->heapsize && h->array[l] > h->array[max]){
        max=l;
    }
    if(r<h->heapsize && h->array[r] > h->array[max]){
        max=r;
    }
    if(max!=i){
        swap(h->array[max],h->array[i]);
        maxheapify(h,max);
    }
}
void buildmaxheap(heapsort h){
    for(int i=h->heapsize/2-1;i>=0;i--){
        maxheapify(h,i);
    }
}
void heap_sort(heapsort h){
    buildmaxheap(h);
    int originalsize=h->heapsize;
    for(int i=originalsize-1;i>=1;i--){
        swap(h->array[i],h->array[0]);
        h->heapsize--;
        maxheapify(h,0);
    }
    h->heapsize=originalsize;
}
int main(){
    int a[]={4,1,3,2,16,9,10,14,8,7};
    heapsort h=create(a,10);
    cout<<"Mang ban dau:\n";
    for(int i=0;i<h->length;i++){
        cout<<h->array[i]<<" ";
    }
    cout<<endl;
    heap_sort(h);
    cout<<"Sau Heap Sort:\n";
    for(int i=0;i<h->length;i++){
        cout<<h->array[i]<<" ";
    }
    cout<<endl;
    return 0;
}