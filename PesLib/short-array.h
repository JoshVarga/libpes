#ifndef SHORT_ARRAY_H
#define SHORT_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct short_array
{
    int count;
    short *pattern;
};

struct short_array *short_array_read(FILE *file);
void short_array_write(FILE *file, struct short_array *data);
void short_array_print(struct short_array* arr);
void short_array_free(struct short_array *arr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SHORT_ARRAY_H */


