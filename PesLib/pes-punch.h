#ifndef CEMBPUNCH_H
#define CEMBPUNCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "block-geometry.h"

struct pes_punch
{
    struct block_geometry *geometry;
};

struct pes_punch *pes_punch_read(FILE *file);
void pes_punch_print(struct pes_punch *item);
void pes_punch_free(struct pes_punch *item);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBPUNCH_H */

