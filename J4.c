#include <stdio.h>
#include <math.h>
int main()
{
    char s[3];
    scanf("%c %c", &s[1],&s[2]);
    if (s[1] == 'B' && s[2] == 'K')
        printf("WIN");
    else if (s[1] == 'B' && s[2] == 'G')
        printf("LOSE");
    else if (s[1] == 'K' && s[2] == 'B')
        printf("LOSE");
    else if (s[1] == 'K' && s[2] == 'G')
        printf("WIN");
    else if (s[1] == 'G' && s[2] == 'K')
        printf("LOSE");
    else if (s[1] == 'G' && s[2] == 'B')
        printf("WIN");
    else if (s[1] == 'B' && s[2] == 'B')
        printf("DRAW");
    else if (s[1] == 'K' && s[2] == 'K')
        printf("DRAW");
    else
        printf("DRAW");
}