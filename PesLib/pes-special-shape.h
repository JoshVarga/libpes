#ifndef CEMBSPECIALSHAPE_H
#define CEMBSPECIALSHAPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "block-geometry.h"
#include "pes-point.h"

struct pes_special_shape
{
    struct stitch_block_description *header;
    short v0;
    
    short NumberOfPoints;
    struct pes_point **points;

    short v1;
    short v2;
    short v3;
    short v4;
    short v5;
    short v6;
    short v7;
    short v8;
    short v9;
    short v10;
    short v11;
    short v12;
    short v13;
    short v14;
    short v15;
    short v16;
};

struct pes_special_shape *pes_special_shape_read(FILE *file);
void pes_special_shape_print(struct pes_special_shape *shape);
void pes_special_shape_free(struct pes_special_shape *shape);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBSPECIALSHAPE_H */

