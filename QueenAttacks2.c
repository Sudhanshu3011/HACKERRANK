#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char *ltrim(char *);
char *rtrim(char *);
char **split_string(char *);

int parse_int(char *);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int **obstacles)
{
    int up, down, left, right, leftup, rightup, leftdown, rightdown;

    if ((c_q > n) || (r_q > n))
    {
        return 0;
    }

    // trasversing up and down
    up = n - r_q;
    down = r_q - 1;

    // trasversing left and right
    right = n - c_q;
    left = c_q - 1;

    // trasversing the left up daigonal
    if (left <= up)
    {
        leftup = left;
    }
    else
    {
        leftup = up;
    }

    // traversing the right up daigonal
    if (right <= up)
    {
        rightup = right;
    }
    else
    {
        rightup = up;
    }

    // traversing the right down daigonal
    if (right <= down)
    {
        rightdown = right;
    }
    else
    {
        rightdown = down;
    }

    // traversing the left down daigonal
    if (left <= down)
    {
        leftdown = left;
    }
    else
    {
        leftdown = down;
    }

    // printf("%d ", (up + down + left + right + leftup + rightup + leftdown + rightdown));
    //  now tackling with the obstacles

    for (int i = 0; i < k; i++)
    {
        int rowobs, colobs;

        rowobs = obstacles[i][0];
        colobs = obstacles[i][1];

        if ((rowobs < 0) || (colobs < 0))
        {
            return 0;
        }
        // left obstacle
        if (r_q == rowobs && c_q > colobs)
        {
            if (left > c_q - colobs - 1)
            {
                left = c_q - colobs - 1;
            }
        }
        // left obstacle

        // right obstacle
        else if (r_q == rowobs && c_q < colobs)
        {
            if (right > colobs - c_q - 1)
            {
                right = colobs - c_q - 1;
            }
        }

        // up obstacle
        else if (c_q == colobs && r_q < rowobs)
        {
            if (up > rowobs - r_q - 1)
            {
                up = rowobs - r_q - 1;
            }
        }

        // down obstacle
        else if (c_q == colobs && r_q > rowobs)
        {
            if (down > r_q - rowobs - 1)
            {
                down = r_q - rowobs - 1;
            }
        }

        // upleft obstacle
        else if ((rowobs > r_q) && (c_q > colobs))
        {
            if ((rowobs - r_q) == (c_q - colobs))
            {
                if (rowobs - r_q - 1 < leftup)
                {
                    leftup = rowobs - r_q - 1;
                }
            }
        }

        // upright obstacle
        else if ((rowobs > r_q) && (c_q < colobs))
        {

            if ((rowobs - r_q) == (colobs - c_q))
            {
                if (colobs - c_q - 1 < rightup)
                {
                    rightup = rowobs - r_q - 1;
                }
            }
        }
        // downright obstacle
        else if ((rowobs < r_q) && (c_q < colobs))
        {
            if ((r_q - rowobs) == (colobs - c_q))
            {
                if (colobs - c_q - 1 < rightdown)
                {
                    rightdown = colobs - c_q - 1;
                }
            }
        }

        // leftdown obstacle
        //  else ((r_q-rowobs)==(c_q-colobs))
        else if ((rowobs < r_q) && (c_q > colobs))
        {
            if ((r_q - rowobs) == (c_q - colobs))
            {
                if (c_q - colobs - 1 < leftdown)
                {
                    leftdown = c_q - colobs - 1;
                }
            }
        }
    }

    int result = (up + down + left + right + leftup + rightup + leftdown + rightdown);
    return result;
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char **first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char **second_multiple_input = split_string(rtrim(readline()));

    int r_q = parse_int(*(second_multiple_input + 0));

    int c_q = parse_int(*(second_multiple_input + 1));

    int **obstacles = malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++)
    {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char **obstacles_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++)
        {
            int obstacles_item = parse_int(*(obstacles_item_temp + j));

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, k, 2, obstacles);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char *data = malloc(alloc_length);

    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char *ltrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char *end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char **split_string(char *str)
{
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char *) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char *str)
{
    char *endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}
