#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "short-array.h"

struct short_array *short_array_read(FILE *file)
{
    int i;
    struct short_array *data = (struct short_array *) malloc(sizeof(struct short_array));
    data->count = binaryReadInt16(file);
    data->pattern = (short *) calloc(data->count, sizeof(short));
    for (i = 0; i < data->count; i++)
    {
        data->pattern[i] = binaryReadInt16(file);
    }
    return data;
}

void short_array_write(FILE *file, struct short_array *data)
{
    int i;
    binaryWriteInt16(file, data->count);
    for (i = 0; i < data->count; i++)
    {
         binaryWriteInt16(file, data->pattern[i]);
    }
}

void short_array_print(struct short_array *data)
{
    int i;
    printf("LENGTH: %d\n", data->count);
    printf("=========================\n");
    for (i = 0; i < data->count; i++)
    {
        printf("%d\n", data->pattern[i]);
    }
    printf("\n");
}

void short_array_free(struct short_array *arr)
{
    free(arr->pattern);
    free(arr);
}