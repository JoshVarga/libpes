#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes-thread.h"

struct thread_data *thread_data_read(FILE *file)
{
    struct thread_data *data;
    data = (struct thread_data *)malloc(sizeof(*data));
    
    data->color_code_length = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)data->color_code, data->color_code_length);
    data->color_code[data->color_code_length] = '\0';

    data->red = binaryReadByte(file);
    data->green = binaryReadByte(file);
    data->blue = binaryReadByte(file);
    data->unknown1 = binaryReadByte(file);
    data->unknown2 = binaryReadInt32(file); // 10 normal, 2 custom?

    data->ThreadNameStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)data->ThreadName, data->ThreadNameStringLength);
    data->ThreadName[data->ThreadNameStringLength] = '\0';

    data->CatalogStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)data->Catalog, data->CatalogStringLength);
    data->Catalog[data->CatalogStringLength] = '\0';

    data->ThreadChartStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)data->ThreadChart, data->ThreadChartStringLength);
    data->ThreadChart[data->ThreadChartStringLength] = '\0';

    return data;
}

void thread_data_print(struct thread_data *thread)
{
    printf("THREAD CHART:  %s\n", thread->ThreadChart);
    printf("CATALOG:       %s\n", thread->Catalog);
    printf("COLOR CODE:    %s\n", thread->color_code);
    printf("THREAD NAME:   %s\n", thread->ThreadName);
    printf("RED:           %d\n", thread->red);
    printf("GREEN:         %d\n", thread->green);
    printf("BLUE:          %d\n", thread->blue);
    printf("CHART NUMBER:  %d\n", thread->unknown2);
}

void thread_data_free(struct thread_data *thread)
{
    free(thread);
}
