#include <stdlib.h>
#include "helpers-binary.h"
#include "point.h"

struct point *point_new(short x, short y)
{
    struct point *newPoint;
    newPoint = (struct point *) malloc(sizeof(*newPoint));
    newPoint->x = x;
    newPoint->y = y;
    return newPoint;
}

struct point *point_read(FILE *file)
{
    struct point *newPoint;
    newPoint = (struct point *) malloc(sizeof(*newPoint));
    newPoint->x = binaryReadInt16(file);
    newPoint->y = binaryReadInt16(file);
    return newPoint;
}

void point_print(struct point *item)
{
    printf("POINT (%d, %d)\n", item->x, item->y);
}

void point_free(struct point *item)
{
    free(item);
}
