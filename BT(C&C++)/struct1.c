#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
struct point{
    char a[100];
    int x;
    int y;
};
typedef struct point diem;
int main(){
  diem p;
  scanf("%s",p.a);
  p.x=100;
  p.y=12;
  printf("Point: (%d, %d)", p.x, p.y);
  printf("\n%s",p.a);
}