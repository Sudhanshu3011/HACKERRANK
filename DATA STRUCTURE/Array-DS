#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, num, *arr, temp;
    // int a1[num];
    scanf("%d", &num);
    arr = (int *)malloc(num * sizeof(int));

    for (j = 0; j < num; j++)
    {
        scanf("%d", arr + j);
    }

    for (i = 0, j = num - 1; i < num / 2; i++, j--)
    {
        temp = *(arr + j);
        *(arr + j) = *(arr + i);
        *(arr + i) = temp;
    }
    for (i = 0; i < num; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}