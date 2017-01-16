#ifndef CEMBMTEXT_H
#define CEMBMTEXT_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include "block-geometry.h"
#include "pes-letter.h"

struct pes_mtext
{
    struct block_geometry *geometry;
    struct pes_letter *letter;
};

struct pes_mtext *pes_mtext_read(FILE *file);
void pes_mtext_print(struct pes_mtext *text);
void pes_mtext_free(struct pes_mtext *text);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBMTEXT_H */

