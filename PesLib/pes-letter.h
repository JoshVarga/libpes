#ifndef CLETTER_H
#define CLETTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct pes_letter
{
    unsigned short character;
    unsigned short unknown;
    unsigned short fontIndex;
    struct stitch_block_description* block;
};

struct pes_letter *pes_letter_read(FILE *file);
void pes_letter_print(struct pes_letter *letter);
void pes_letter_free(struct pes_letter *letter);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLETTER_H */

