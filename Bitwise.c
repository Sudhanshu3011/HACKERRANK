#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void calculate_the_maximum(int n, int k)
{
    int i, j, and = 0, or = 0, xnor = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = n; j > i; j--)

        {

            if ((i & j) > and&&(i & j) < k)
                and = i & j;
            if ((i | j) > or &&(i | j) < k)
                or = i | j;
            if ((i ^ j) > xnor && (i ^ j) < k)
                xnor = i ^ j;
        }
    }
    printf("%d\n", and);
    printf("%d\n", or);
    printf("%d\n", xnor);
}

// printf("%d,%d,%d",max(and[]),)}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}
