#include <bits/stdc++.h>
using namespace std;
struct sinhvien{
    int msv;
    string nickname;
    string dc;
    double gpa;
};
struct sinhvien2{
    int msv;
    string nickname;
    string dc;
    double gpa;
    //constructure1(import default data )
    sinhvien2(){
        msv=102250068;
        nickname="Algoict";
        dc="DaNang";
        gpa=3.24;
    }
    //constructure2
    sinhvien2(int masinhvien,string ten,string address,double average){
        msv=masinhvien;
        nickname=ten;
        dc=address;
        gpa=average;
    }
    void in(){
        cout<<msv<<" "<<nickname<<" "<<dc<<" "<<fixed<<setprecision(2)<<gpa<<endl;
    }
    void nhap(){
        cin>>msv;
        cin.ignore();getline(cin,nickname);getline(cin,dc);
        cin>>gpa;
    }
};
int main(){
    sinhvien2 x{123,"abc","avava",3.3433};
    sinhvien2 y=x;
    x.in();
    sinhvien2 z(321,"asdada","avasdadada",3.99999);
    z.in();
    sinhvien hoang;
    cin>>hoang.msv;
    cin.ignore();
    getline(cin,hoang.nickname);
    getline(cin,hoang.dc);
    cin>>hoang.gpa;
    cout<<hoang.msv<<" "<<hoang.nickname<<" "<<hoang.dc<<" "<<fixed<<setprecision(2)<<hoang.gpa<<endl;   
}