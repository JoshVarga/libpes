#ifndef BLOCK_GEOMETRY_H
#define BLOCK_GEOMETRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "affine-transform.h"

struct block_geometry
{
    short left;
    short top;
    short right;
    short bottom;

    short leftPosition;
    short topPosition;
    short rightPosition;
    short bottomPosition;
    struct affine_transform *transform;
};

struct block_geometry *block_geometry_read(FILE *file);
void block_geometry_write(FILE *file, struct block_geometry *block);
void block_geometry_print(struct block_geometry *block);
void block_geometry_free(struct block_geometry *block);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BLOCK_GEOMETRY_H */

