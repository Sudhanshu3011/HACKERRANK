#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int marks_summation(int *marks, int number_of_students, char gender)
{
    int bmarks = 0, gmarks = 0;
    for (int i = 0; i < number_of_students; i++)
    {
        if (i % 2 == 0)
        {
            bmarks = bmarks + *(marks + i);
        }
        else
        {
            gmarks = gmarks + *(marks + i);
        }
    }
    if (gender == 'b')
    {
        return bmarks;
    }
    else
    {
        return gmarks;
    }
}

int main()
{
    int number_of_students;
    char gender;
    int sum;
    scanf("%d", &number_of_students);
    int *marks = (int *)malloc(number_of_students * sizeof(int));
    for (int student = 0; student < number_of_students; student++)
    {
        scanf("%d", (marks + student));
    }
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    return 0;
}
