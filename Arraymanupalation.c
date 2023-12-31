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

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

// long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {

    //  Approach 1 
    //    int arr[n];
    //     for (int i = 0; i < n; i++) 
    //     {
    //     arr[i] = 0;
    //     }
    //     for (int i=0;i<queries_rows;i++)
    //     {
    //          int l =*(*(queries+i)+0);
    //          int  h =*(*(queries+i)+1);
    //          int   summand=*(*(queries+i)+2);
            
    //         for (int k = l - 1; k < h; k++) {
    //         arr[k] += summand;}
    //     }
              
        
    //     long max=arr[0];
    //     for(int i=0;i<n;i++)
    //     {
    //         if(max<arr[i])
    //         {
    //             max=arr[i];
    //         }
    //     }
    //     return max;
    long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long arr[n + 1]; // Increase array size by 1 to handle 1-indexed queries

    // Initialize array with zeros
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
    }

    // Iterate through queries and update prefix sums
    for (int i = 0; i < queries_rows; i++) {
        int l = *(*(queries + i) + 0);
        int h = *(*(queries + i) + 1);
        int summand = *(*(queries + i) + 2);

        // Update the starting index
        arr[l] += summand;

        // If the ending index is within the array bounds, update it
        if (h + 1 <= n) {
            arr[h + 1] -= summand;
        }
    }

    // Find the maximum value using prefix sums
    long max = arr[1];
    long current = arr[1];
    for (int i = 2; i <= n; i++) {
        current += arr[i];
        if (max < current) {
            max = current;
        }
    }

    return max;
}



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    int** queries = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int queries_item = parse_int(*(queries_item_temp + j));

            *(*(queries + i) + j) = queries_item;
        }
    }

    long result = arrayManipulation(n, m, 3, queries);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
