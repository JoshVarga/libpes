#ifndef POINT_H
#define POINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct point
{
    int16_t x;
    int16_t y;
};

struct pointArray
{
    int count;
    struct point *points;
};

struct point *point_new(int16_t x, int16_t y);
struct point *point_read(FILE *file);
void point_print(struct point *item);
void point_free(struct point *item);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* POINT_H */

