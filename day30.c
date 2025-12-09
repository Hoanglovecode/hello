//Ôn tập xâu ký tự
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ll long long
int main(){
  char a[100]="Lê Văn Hoàng";
  char b[1000]={'a','b','c','d'};
  char c[100];
  printf("%s\n%s",b,a);
  //strlen():độ dài của xâu
  printf("\n%d",strlen(b));//4
  printf("\n");
  //Cách nhập xâu
  scanf("\n%s",c);// không được có dấu cách
  //Duyệt từng ký tự một
  for(int i=0;i<strlen(c);i++){
    printf("%c\n",c[i]);
  }
  getchar();//USE vì đang ở giữa scanf và gets
  //Khi nhập xâu s có dấu cách 
  char d[100];
  gets(d);//trước nó k có phím enter(scanf)
  /*Cách khắc phục là sài getchar()
  hoặc là sài scanf("\n");
  Lưu ý khi sài getchar() là nó ăn một kí tự
  kể cả kí tự xong xâu hay enter
  Vì vậy chỉ dùng getchar ở giữa scanf và gets,
  Ở giữa 2 gets không sài getchar()
  */
  printf("%s",d);
  //Hàm sử dụng nhiều hơn gets mà không bị lỗi chương trình
  char e[100];
  printf("\nMời nhập xâu e:");
  fgets(e,10,stdin);//fgets(Tên xâu,Max kí tự,stdin)
  printf("%s",e);//Nó sẽ in ra 9 kí tự đầu và kí tự cuối là kí tự null '0'
  //Ví dụ dễ hiểu cho kí tự null
  char r[100]="Hello em iu";
  r[6]='\0';
  printf("%s",r);//In ra Hello
  //fgets sẽ đọc lun phím enter nên phải thay thế enter bằng null
  //r[strlen(r)-1]='\0';
  //gets nguy hiểm hơn fgets và nó bất tiện hơn
}