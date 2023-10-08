#include <stdio.h>
#include <string.h>

int main()
{
    int arr[6][6], b, c, i = 0, j = 0, s = 0, max[15], sum = 0, maximum = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    // loop till n-2
    while (i != 4)
    {
        while (j != 4)
        {
            for (int b = i; b <= i + 2 && b <= 5; b++)
            {
                for (int c = j; c <= j + 2 && c <= 5; c++)
                {
                    printf("%d ", arr[b][c]);

                    if (b == i || b == (i + 2) || c == (j + 1))
                    {
                        sum = sum + arr[b][c];
                    }
                }
                printf("\n");
            }
            printf("\n");
            // assiging the value of max element
            max[s] = sum;
            // incrementing s for taking next element in the max[]
            s++;
            // agaim implementing s as 0;
            sum = 0;
            // incrementing the j for moving in the column
            j++;
            printf("\n");
        }
        // again putting the j zero for making the pattern follow for i=1,1=2,...
        j = 0;
        i++;
    }
    // making the s=0 for printing the array max[]
    //((n-2)*(n-2))-1 is the value of s for any n
    s = 0;
    while (s != 16)
    {
        printf("%d ", max[s]);
        s++;
    }
    printf("\n");
    maximum = max[0];
    for (s = 0; s <= 15; s++)
    {

        if (max[s] > maximum)
        {

            maximum = max[s];
        }
    }
    printf("%d", maximum);

    return 0;
}