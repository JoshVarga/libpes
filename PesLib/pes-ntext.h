#ifndef CEMBNTEXT_H
#define CEMBNTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "block-geometry.h"
#include "pes-letter.h"

struct pes_ntext
{
    struct block_geometry *geometry;
    struct pes_letter *letter;
};

struct pes_ntext *pes_ntext_read(FILE *file);
void pes_ntext_print(struct pes_ntext *text);
void pes_ntext_free(struct pes_ntext *text);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBNTEXT_H */

