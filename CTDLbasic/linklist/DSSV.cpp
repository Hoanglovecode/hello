#include <bits/stdc++.h>
using namespace std;
struct Student{
    string ten,lop;
    int msv;
    double gpa;
};
struct SV{
    Student s;
    SV *next;
};
typedef struct SV* sv;
//createnode
sv createnode(){
    Student x;
    cin.ignore();
    cout<<"Enter full name : ";getline(cin,x.ten);
    cout<<"\nEnter class : ";getline(cin,x.lop);
    cout<<"\nEnter mã sinh viên : ";cin>>x.msv;
    cout<<"\nEnter gpa : ";cin>>x.gpa;
    sv newnode=new SV();
    newnode->s=x;
    newnode->next=NULL;
    return newnode;
}
//count
int countt(sv head){
    int dem=0;
    while(head){
        dem++;
        head=head->next;
    }
    return dem;
}
//in riên thông tin của 1 sinh viên
void in(Student s){
    cout<<"---------------------------"<<endl;
    cout<<"Sinh viên:"<<s.ten<<endl;
    cout<<"Lớp sinh hoạt:"<<s.lop<<endl;
    cout<<"Mã sinh viên:"<<s.msv<<endl;
    cout<<"Điểm gpa:"<<fixed<<setprecision(2)<<s.gpa<<endl;
    cout<<"---------------------------"<<endl;
}
//duyet
void inds(sv head){
    cout<<"Danh sách thông tin các sinh viên"<<endl;
    while(head){
        in(head->s);
        head=head->next;
    }
    cout<<endl;
}
//pushfront
void pushfront(sv &head){
    sv nodeA=createnode();
    nodeA->next=head;
    head=nodeA;
}
//pushback
void pushback(sv &head){
    sv nodeB=createnode();
    if(head==NULL){
        head=nodeB;
        return;
    }
    sv tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
}
//pushmiddle
void insert(sv &head,int k){
    int n=countt(head);
    if(k<1 || k>n+1)return;
    if(k==1){
        pushfront(head);
        return;
    }
    sv tmp=head;
    sv nodeC=createnode();
    for(int i=1;i<k-1;i++){
        tmp=tmp->next;
    }
    nodeC->next=tmp->next;
    tmp->next=nodeC;
}
//popfront
void popfront(sv &head){
    if(head==NULL)return;
    sv tmp=head;
    head=tmp->next;
    delete(tmp);
}
//popback
void popback(sv &head){
    if(head==NULL)return;
    sv tmp=head;
    if(tmp->next==NULL){
        delete(tmp);
        head=NULL;
        return;
    }
    while(tmp->next->next){
        tmp=tmp->next;
    }
    sv last=tmp->next;
    tmp->next=NULL;
    delete(last);
}
//popmiddle
void popmiddle(sv &head,int k){
    if(head==NULL)return;
    int n=countt(head);
    if(k<1||k>n)return;
    if(k==1){
        popfront(head);
        return;
    }
    sv tmp=head;
    for(int i=1;i<k-1;i++){
        tmp=tmp->next;
    }
    sv nodeK=tmp->next;
    tmp->next=nodeK->next;
    delete(nodeK);
}
//empty
bool empty(sv head){
    return head==NULL;
}
//sortincrease
void sortincrease(sv &head){
    for(sv i=head;i!=NULL;i=i->next){
        sv min=i;
        for(sv j=i->next;j!=NULL;j=j->next){
            if(min->s.gpa>j->s.gpa){
                min=j;
            }
        }
        Student tmp=min->s;
        min->s=i->s;
        i->s=tmp;
    }
}
//sortdecrease
void sortdecrease(sv &head){
    for(sv i=head;i!=NULL;i=i->next){
        sv max=i;
        for(sv j=i->next;j!=NULL;j=j->next){
            if(max->s.gpa<j->s.gpa){
                max=j;
            }
        }
        Student tmp=max->s;
        max->s=i->s;
        i->s=tmp;
    }
}
//reverse
void revearse(sv &head){
    if(head==NULL)return;
    sv cur=head;
    sv pre=NULL;
    sv tmp;
    while(cur){
        tmp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
    }
    head=pre;
}
int main(){
    sv head=NULL;
    while(1){
        cout << "-----------------MENU---------------\n";
		cout << "1. Thêm sinh viên vào đầu danh sách\n";
		cout << "2. Thêm sinh viên vào cuối danh sách\n";
		cout << "3. Thêm sinh viên vào giữa danh sách\n";
		cout << "4. Xóa sinh viên đầu danh sách\n";
		cout << "5. Xóa sinh viên cuối danh sách\n";
		cout << "6. Xóa sinh viên giữa danh sách\n";
		cout << "7. Duyệt danh sách sinh viên\n";
		cout << "8. Sắp xếp điểm gpa danh sách sinh viên tăng dần rồi in ra\n";
        cout << "9. Sắp xếp điểm gpa danh sách sinh viên giảm dần rồi in ra\n";
        cout << "10. Đảo ngược danh sách sinh viên rồi in ra\n";
		cout << "0. Stop running program !\n";
		cout << "-------------------------------------\n";
		cout << "Nhập lựa chọn số:";
        int choice;cin>>choice;
        if(choice==1){
            pushfront(head);
        }
        else if(choice==2){
            pushback(head);
        }
        else if(choice==3){
            int k;cout<<"Nhập vị trí cần chèn:";cin>>k;
            insert(head,k);
        }
        else if(choice==4){
            popfront(head);
        }
        else if(choice==5){
            popback(head);
        }
        else if(choice==6){
            int k;cout<<"Nhập vị trí cần xóa:";cin>>k;
            popmiddle(head,k);
        }
        else if(choice==7){
            inds(head);
        }
        else if(choice==8){
            sortincrease(head);
            inds(head);
        }
        else if(choice==9){
            sortdecrease(head);
            inds(head);
        }
        else if(choice==10){
            revearse(head);
            inds(head);
        }
        else if(choice==0){
            break;
        }
    }
    return 0;
}