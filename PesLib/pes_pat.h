#ifndef PAT_H
#define PAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "tile-line.h"

struct pes_pat
{
    short count;
    struct tile_line **tile_lines;
};

struct pes_pat *pes_pat_read(FILE *file);
void pes_pat_print(struct pes_pat *fill);
void pes_pat_free(struct pes_pat *patToFree);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PAT_H */

