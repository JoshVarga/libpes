#ifndef CEMBONE_H
#define CEMBONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "affine-transform.h"
#include "block-geometry.h"

struct pes_one
{
    struct block_geometry *geometry;
            
    short unknown;
    short translate_x;
    short translate_y;
    short width;
    short height;
    unsigned char other[8];
};

struct pes_one *pes_one_read(FILE *file);
void pes_one_print(struct pes_one *);
void pes_one_free(struct pes_one *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBONE_H */

