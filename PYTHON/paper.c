#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
struct Symbol{
    const char *name;
    int val;
};
struct Node{
    struct Node*next;
    struct Symbol *element;
};
int main(){
    struct Symbol onesym,twosym,threesym;
    onesym.name= "One";onesym.val=1;
    twosym.name="two";twosym.val=1;
    threesym.name="three";threesym.val=1;
    struct Node *nodeA;
    struct Node *nodeB;
    struct Node *nodeC;

    nodeA=(struct Node*)malloc(sizeof(struct Node));
    nodeB=(struct Node*)malloc(sizeof(struct Node));
    nodeC=(struct Node*)malloc(sizeof(struct Node));

    nodeA->next=nodeB;
    nodeA->element=&onesym;

    nodeB->element=&twosym;
    nodeB->next=nodeC;
    nodeC->next=NULL;
    nodeC->element=&threesym;

    struct Node*nodeP=nodeA;
    while(nodeP != NULL){
        printf("Name:%s   Value:%d",nodeP->element->name,nodeP->element->val);
        nodeP=nodeP->next;
    }
    free(nodeA);
    free(nodeB);
    free(nodeC);
}