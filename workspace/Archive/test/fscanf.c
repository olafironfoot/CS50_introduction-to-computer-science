#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char test[10];
    FILE* fp = fopen("large", "r");
    fscanf(fp, "%s", test);
    printf("%s\n", test);
}