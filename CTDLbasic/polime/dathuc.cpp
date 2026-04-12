#include <iostream>
using namespace std;

struct Node{
    int coef;
    int exp;
    Node* next;
};

typedef Node* node;

// tao node moi
node createNode(int coef, int exp) {
    node newnode = new Node;
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = nullptr;
    return newnode;
}

// chen vao da thuc
void insert(node &head, int coef, int exp) {
    if(coef == 0) return;

    node newnode = createNode(coef, exp);

    if(head == nullptr || head->exp < exp) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node tmp = head;

    while(tmp->next != nullptr && tmp->next->exp > exp) {
        tmp = tmp->next;
    }

    if(tmp->next != nullptr && tmp->next->exp == exp) {
        tmp->next->coef += coef;

        if(tmp->next->coef == 0) {
            node del = tmp->next;
            tmp->next = del->next;
            delete del;
        }

        delete newnode;
    }
    else {
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
}

// nhap
void input(node &head) {
    int n;
    cout << "Nhap so hang tu: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int coef, exp;
        cout << "Nhap he so va so mu: ";
        cin >> coef >> exp;
        insert(head, coef, exp);
    }
}

// in
void printPoly(node head) {
    if(head == nullptr) {
        cout << "0\n";
        return;
    }

    while(head != nullptr) {
        cout << head->coef << "x^" << head->exp;
        if(head->next != nullptr) cout<<(head->next->coef > 0 ? " + " : " - ");
        head = head->next;
    }
    cout << endl;
}

// cong
node add(node p1, node p2) {
    node res = nullptr;

    while(p1 != nullptr && p2 != nullptr) {
        if(p1->exp > p2->exp) {
            insert(res, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if(p1->exp < p2->exp) {
            insert(res, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else {
            insert(res, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while(p1 != nullptr) {
        insert(res, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while(p2 != nullptr) {
        insert(res, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return res;
}

// nhan
node multiply(node p1, node p2) {
    node res = nullptr;

    for(node i = p1; i != nullptr; i = i->next) {
        for(node j = p2; j != nullptr; j = j->next) {
            insert(res, i->coef * j->coef, i->exp + j->exp);
        }
    }

    return res;
}

// main
int main() {
    node p1 = nullptr, p2 = nullptr;

    cout << "Nhap da thuc 1:\n";
    input(p1);

    cout << "Nhap da thuc 2:\n";
    input(p2);

    cout << "Da thuc 1: ";
    printPoly(p1);

    cout << "Da thuc 2: ";
    printPoly(p2);

    node sum = add(p1, p2);
    cout << "Tong: ";
    printPoly(sum);

    node mul = multiply(p1, p2);
    cout << "Tich: ";
    printPoly(mul);

    return 0;
}