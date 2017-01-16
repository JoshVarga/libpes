#ifndef PES_POINT_H
#define PES_POINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "point.h"

struct pes_point
{
    short stitch_type;
    struct point *p1;
    struct point *p2;
    struct point *p3;
};

struct pes_point *pes_point_read(FILE *file);
void pes_point_print(struct pes_point *line);
void pes_point_free(struct pes_point *point);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PES_POINT_H */

