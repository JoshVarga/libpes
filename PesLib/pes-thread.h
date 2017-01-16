#ifndef PES_THREAD_H
#define PES_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct thread_data
{
    unsigned char color_code_length;
    char color_code[50];
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char unknown1; /* 0 - padding rgb? */
    int unknown2; // 10 normal, 2 custom?
    unsigned char ThreadNameStringLength;
    char ThreadName[50];
    unsigned char CatalogStringLength;
    char Catalog[50];
    unsigned char ThreadChartStringLength;
    char ThreadChart[50];
};

struct thread_data *thread_data_read(FILE *file);
void thread_data_print(struct thread_data *thread);
void thread_data_free(struct thread_data *thread);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PES_THREAD_H */

