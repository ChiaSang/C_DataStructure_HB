#include <stdio.h>

typedef int ZHAO; //两者为等价的

typedef struct Student
{
    int sid;
    char name;
    char sex;
}ST, *SPTR;

int main()
{
    int i = 10;
    ZHAO j = 20;
    printf("%d\n", j);
    return 0;
}
