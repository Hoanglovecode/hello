#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    char a[n][100];
    for(int i=0;i<n;i++){
        scanf("%s\n",&a[i]);
    }
    for(int i=0;i<n;i++){
        int dem=0;
        for(int j=0;j<strlen(a[i])/2;j++){
            if(a[i][j]!=a[i][strlen(a[i])-1-j])dem++;
        }
        if(dem<=2)printf("YES");
        else printf("NO");
    }
}


