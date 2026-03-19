#include <bits/stdc++.h>
using namespace std;
struct sophuc{
    int a,b;
    //option 1
    // sophuc operator + (const sophuc other){
    //     sophuc tong;
    //     tong.a=a+other.a;
    //     tong.b=b+other.b;
    //     return tong;
    // }
    //option 2
    friend sophuc operator+(const sophuc x,const sophuc y){
        sophuc tong;
        tong.a=x.a+y.a;
        tong.b=x.b+y.b;
        return tong;
    }
    friend istream& operator >>(istream& in,sophuc &x){
        in>>x.a>>x.b;
        return in;
    }
    friend ostream& operator<<(ostream & out,sophuc x){
        out<<x.a<<" "<<x.b;
        return out;
    }
    //BOOL
    //option1
    // bool operator ==(const sophuc other){
    //     return a==other.a && b==other.b;
    // }
    //option2
    friend bool operator == (const sophuc x,const sophuc y){
        return x.a==y.a && x.b==y.b;
    }
};
int main(){
    sophuc a{1,2},b{3,4};
    sophuc c=a+b;
    cout<<c.a<<" "<<c.b<<endl;
    sophuc d,e;
    cin>>d>>e;
    sophuc f=d+e;
    cout<<f<<endl;
    if(d==e)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}