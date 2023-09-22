#include <stdio.h>
#include <stdlib.h>
int rotate(int *arr, int n, int ind)
{
    int temp, s = 0;
    int *ar = (int *)malloc(n * sizeof(int));
    while (s != ind)
    {
        *(ar +(n-1)) = *(arr);
        for (int i = 0; i < n - 1; i++)
        {
            temp = *(arr +( i +1));
            *(ar + i ) = temp;
        }
        for (int i = 0; i < n; i++)
        {
            temp = *(ar + i);
            *(arr + i) = temp;
        }
        s++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    free(arr);
    free(ar);
    return 0;
}
int main()
{
    int temp, n, ind, a = 0;
    scanf("%d %d", &n, &ind);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    rotate(arr, n, ind);

    return 0;
}
