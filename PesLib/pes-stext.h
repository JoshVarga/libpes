#ifndef CEMBSTEXT_H
#define CEMBSTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "block-geometry.h"
#include "pes-letter.h"

struct pes_stext
{
    struct block_geometry *geometry;
    struct pes_letter *letter;
};

struct pes_stext *pes_stext_read(FILE *file);
void pes_stext_print(struct pes_stext *text);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBSTEXT_H */

