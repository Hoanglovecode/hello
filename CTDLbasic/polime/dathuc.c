// bai 2
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int coef;      // he so
    int exp;       // so mu
    struct node *next;
} node;
// tao node moi
node* createNode(int coef, int exp) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}
// chen vao da thuc (theo thu tu giam dan theo exp)
void insert(node **head, int coef, int exp) {
    if(coef == 0) return;
    node *newnode = createNode(coef, exp);
    if(*head == NULL || (*head)->exp < exp) {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    node *tmp = *head;
    // tim vi tri chen
    while(tmp->next != NULL && tmp->next->exp > exp) {
        tmp = tmp->next;
    }
    // neu trung bac cong he so
    if(tmp->next != NULL && tmp->next->exp == exp) {
        tmp->next->coef += coef;
        if(tmp->next->coef == 0) { // neu =0 thi xoa
            node *del = tmp->next;
            tmp->next = del->next;
            free(del);
        }
        free(newnode);
    }
    else {
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
}
// nhap da thuc
void input(node **head) {
    int n;
    printf("Nhap so hang tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int coef, exp;
        printf("Nhap he so va so mu: ");
        scanf("%d %d", &coef, &exp);
        insert(head, coef, exp);
    }
}
// in da thuc
void printPoly(node *head) {
    if(head == NULL) {
        printf("0\n");
        return;
    }
    while(head != NULL) {
        printf("%dx^%d", head->coef, head->exp);
        if(head->next != NULL) printf(" + ");
        head = head->next;
    }
    printf("\n");
}
// cong 2 da thuc
node* add(node *p1, node *p2) {
    node *res = NULL;
    while(p1 != NULL && p2 != NULL) {
        if(p1->exp > p2->exp) {
            insert(&res, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if(p1->exp < p2->exp) {
            insert(&res, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else {
            insert(&res, p1->coef + p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL) {
        insert(&res, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while(p2 != NULL) {
        insert(&res, p2->coef, p2->exp);
        p2 = p2->next;
    }
    return res;
}
// nhan 2 da thuc
node* multiply(node *p1, node *p2) {
    node *res = NULL;
    for(node *i = p1; i != NULL; i = i->next) {
        for(node *j = p2; j != NULL; j = j->next) {
            insert(&res, i->coef * j->coef, i->exp + j->exp);
        }
    }
    return res;
}
// main
int main() {
    node *p1 = NULL, *p2 = NULL;

    printf("Nhap da thuc 1:\n");
    input(&p1);

    printf("Nhap da thuc 2:\n");
    input(&p2);

    printf("Da thuc 1: ");
    printPoly(p1);

    printf("Da thuc 2: ");
    printPoly(p2);

    node *sum = add(p1, p2);
    printf("Tong: ");
    printPoly(sum);

    node *mul = multiply(p1, p2);
    printf("Tich: ");
    printPoly(mul);

    return 0;
}