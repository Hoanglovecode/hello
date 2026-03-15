#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>v(3,100);
    v.push_back(1);//{100,100,100,1}
    v.push_back(2);//{100,100,100,1,2}
    v.push_back(3);//{100,100,100,1,2,3}
    cout<<v.size()<<endl;//6
    //Duyệt vòng cách 1
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //Duyệt vòng cách 2
    for(int i:v){//range base for loop
        cout<<i<<" ";
    }
    vector<int>::iterator a=v.begin();
    a++;
    a+=2;
    cout<<"\n"<<*a<<endl;
    //Cách 3:duyệt vecto bằng iterator
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();i++){
        cout<<*i<<' ';
    }
    cout<<endl;
    //Cách nhập từng phần tử đẩy vào vector
    //cách 1
    vector<int>v2;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        v2.push_back(temp);
    }
    for(int x:v2){
        cout<<x<<' ';
    }
    cout<<endl;
    //cách 2
    int m;cin>>m;
    vector<int>v3(m);
    for(int i=0;i<m;i++)cin>>v3[i];
    for(int x:v3)cout<<x<<" ";
    //Chèn phần tử
    v3.insert(v3.begin()+1,1000);
    cout<<endl;
    for(int x:v3)cout<<x<<" ";
    //Xóa phần tử
    cout<<endl;
    v3.erase(v3.begin()+1);
    v3.erase(v3.begin()+v3.size()-1);//v.pop_back()
    for(auto x:v3)cout<<x<<" ";
    //vector<int>::iterator = auto
}
/*
Function	Description
v.assign(5,100)	Fills a vector with multiple values : 100 100 100 100 100
v.at(1)	    Returns an indexed element from a vector
v.back()	    Returns the last element of a vector
begin()	    Returns an iterator pointing to the beginning of a vector
capacity()	Returns the number of elements that a vector's reserved memory is able to store
clear()	    Removes all of the contents of a vector
data()	    Returns a pointer to the block of memory where a vector's elements are stored
empty()  	Checks whether a vector is empty or not
end()	    Returns an iterator pointing to the end of a vector
v.front() 	Returns the first element of a vector
insert(v.begin()+i,value)	Inserts a number of elements into a vector
erase(v.begin()+i,value)	    Removes a number of elements from a vector
max_size()	Returns the maximum number of elements that a vector can have
pop_back()	Removes the last element of a vector
push_back(value)	Adds an element to the end of a vector
rbegin()	Returns a reverse iterator pointing to the last element of a vector
rend()  	Returns a reverse iterator pointing to a position right before the first element of a vector
reserve()	Reserves memory for a vector
resize()	Changes the size of a vector, adding or removing elements if necessary
shrink_to_fit()	Reduces the reseved memory of a vector if necessary to exactly fit the number of elements
size()  	Returns the number of elements in a vector
swap()  	Swaps the contents of one vector with another
*/