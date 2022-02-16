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
#include <stdbool.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);
int get_total(int, int*);

bool is_chaotic(int, int*);
bool is_sorted(int, int*);

/*
 * Complete the 'minimum_bribes' function below.
 * The function accepts following parameters: (1) INTEGER q_count; (2) INTEGER_ARRAY q.
 * The function return is VOID (prints a message).
 */
void minimum_bribes(int q_count, int* q) {
    /* Initialize bribes counter. */
    int* bribes = malloc(sizeof(int) * q_count);
    for(int i = 0; i < q_count; i++)
        bribes[i] = 0;
    
    /* Bubble Sort only swaps adjacent elements, as we need. */
    while(!is_sorted(q_count, q))  // Iterate until q is sorted.
        for(int j = 0; j < q_count - 1; j++) {
            if(q[j] > q[j+1]) {
                bribes[q[j]-1]++;  // q[j] is bribing someone.
                int aux = q[j];
                q[j] = q[j+1];
                q[j+1] = aux;
            }
        }
    
    printf("%d\n", get_total(q_count, bribes));
}

bool is_chaotic(int q_count, int* q) {
    for(int i = 0; i < q_count; i++)
        if((abs(q[i]-1) - i) > 2)
            return true;

    return false;
}

int get_total(int n, int* a) {
    int total = 0;
    for(int i = 0; i < n; i++)
        total += a[i];
        
    return total;
}

bool is_sorted(int n, int* a) {
    for(int i = 0; i < n - 1; i++)
        if(a[i] > a[i+1])
            return false;

    return true;
}

int main() {
    int t = parse_int(ltrim(rtrim(readline())));

    for(int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));
        char** q_temp = split_string(rtrim(readline()));
        int* q = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int q_item = parse_int(*(q_temp + i));
            *(q + i) = q_item;
        }

        /* Check for bribes amounts bigger than 2. */
        if(is_chaotic(n, q))
            printf("Too chaotic\n");
        else
            minimum_bribes(n, q);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while(true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if(!line)
            break;

        data_length += strlen(cursor);
        if(data_length < alloc_length - 1 || data[data_length - 1] == '\n')
            break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if(!data) {
            data = '\0';
            break;
        }
    }

    if(data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);

        if(!data)
            data = '\0';
    } else {
        data = realloc(data, data_length + 1);

        if(!data)
            data = '\0';
        else
            data[data_length] = '\0';
    }

    return data;
}

char* ltrim(char* str) {
    if(!str)
        return '\0';

    if(!*str)
        return str;

    while(*str != '\0' && isspace(*str))
        str++;

    return str;
}

char* rtrim(char* str) {
    if(!str)
        return '\0';

    if(!*str)
        return str;

    char* end = str + strlen(str) - 1;
    while(end >= str && isspace(*end))
        end--;

    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;

    while(token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if(!splits)
            return splits;

        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if(endptr == str || *endptr != '\0')
        exit(EXIT_FAILURE);

    return value;
}
