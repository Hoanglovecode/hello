#include <bits/stdc++.h>
using namespace std;
struct Node{
    string cccd,hoten,mack;
    int socophieu;
    Node* next;
    Node* pre;
};
typedef struct Node* node;
node createnode(string cccd,string hoten,string mack,int socophieu){
    node newnode=new Node;
    newnode->cccd=cccd;
    newnode->hoten=hoten;
    newnode->mack=mack;
    newnode->socophieu=socophieu;
    newnode->next=nullptr;
    newnode->pre=nullptr;
    return newnode;
}
void pushback(node &head,string cccd,string hoten,string mack,int socophieu){
    node nodeB=createnode(cccd,hoten,mack,socophieu);
    if(head==NULL){
        head=nodeB;
        return;
    }
    node tmp=head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=nodeB;
    nodeB->pre=tmp;
}
void duyet(node head){
    node tmp=head;
    while(tmp){
        cout<<tmp->cccd<<'|'<<tmp->hoten<<'|'<<tmp->mack<<'|'<<tmp->socophieu<<endl;
        tmp=tmp->next;
    }
}
void nhapdanhsach(node &head){
    int n;
    cout<<"Nhap so nguoi:";cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string cccd,hoten,mack;
        int socophieu;
        cout<<"\nHumman:"<<i<<endl;
        cout<<"So CCCD:";getline(cin,cccd);
        cout<<"Ho va ten:";getline(cin,hoten);
        cout<<"Ma chung khoan:";getline(cin,mack);
        cout<<"So co phieu:";cin>>socophieu;
        cin.ignore();
        pushback(head,cccd,hoten,mack,socophieu);
    }
}
void findhummanmack(node head,string x){
    node tmp=head;
    bool found=false;
    while(tmp){
        if(tmp->mack==x){
            cout<<tmp->cccd<<'|'<<tmp->hoten<<'|'<<tmp->mack<<'|'<<tmp->socophieu<<endl;
            found=true;
        }
        tmp=tmp->next;
    }
    if(found==false) cout<<"Not Found"<<endl;
}
void findhummanhighestsocophieu(node head){
    if(head==nullptr)return;
    int maxx=head->socophieu;
    node tmp=head->next;
    while(tmp){
        maxx=max(maxx,tmp->socophieu);
        tmp=tmp->next;
    }
    cout<<"Nguoi co so co phieu cao nhat:"<<endl;
    tmp=head;
    while(tmp){
        if(tmp->socophieu==maxx){
            cout<<tmp->cccd<<'|'<<tmp->hoten<<'|'<<tmp->mack<<'|'<<tmp->socophieu<<endl;
        }
        tmp=tmp->next;
    }
}
void deletehummancccd(node &head,string x){
    if(head==nullptr)return;
    node tmp=head;
    while(tmp){
        if(tmp->cccd==x){
            if(tmp==head){
                head=head->next;
                if(head){
                    head->pre=nullptr;
                }
                delete(tmp);
            }
            else{
                tmp->pre->next=tmp->next;
                if(tmp->next)tmp->next->pre=tmp->pre;
                delete(tmp);
            }
            cout<<"Finished delete"<<endl;
            return;
        }
        tmp=tmp->next;
    }
    cout<<"Not Found cccd to delete"<<endl;
}
int main(){
   node head=nullptr;

   nhapdanhsach(head);
   cout<<"List people who have highest assets in VietNam:"<<endl;
   duyet(head);

   string mack;
   cout<<"Nhap ma chung khoan nhung nguoi can tim:";
   getline(cin,mack);
   findhummanmack(head,mack);

   findhummanhighestsocophieu(head);

   string cccd;
   cout<<"Nhap so cccd can xoa:";
   getline(cin,cccd);
   deletehummancccd(head,cccd);
   
   cout<<"List people after you delete:\n";
   duyet(head);
}