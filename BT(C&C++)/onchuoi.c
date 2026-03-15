#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int cmp(const void*a,const void *b){
  char *x=(char*)a;
  char *y=(char*)b;
  if(strlen(x)!=strlen(y)) return strlen(x)-strlen(y);
  else return strcmp(x,y);
}
int main(){
  char s[1000];
  fgets(s,1000,stdin);
  s[strcspn(s,"\n")]='\0';
  char a[100][100];
  char *token=strtok(s," ");
  int n=0;
  while(token!=NULL){
    strcpy(a[n],token);
    token=strtok(NULL," ");
    n++;
  }
  qsort(a,n,sizeof(a[0]),cmp);
  for(int i=0;i<n;i++)printf("%s ",a[i]);
}