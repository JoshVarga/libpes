#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes-letter.h"
#include "stitch-block-description.h"

struct pes_letter *pes_letter_read(FILE *file)
{
    struct pes_letter *letter = (struct pes_letter *) malloc(sizeof(struct pes_letter));
    letter->character = binaryReadUInt16(file);
    letter->unknown = binaryReadUInt16(file);
    //letter->block = stitch_block_description_read(file);
    return letter;
}

void pes_letter_print(struct pes_letter *letter)
{
    printf("LETTER\n");
    printf("=================\n");
    printf("Letter: %c\n", letter->character);
    printf("Unknown: %d\n", letter->unknown);
    stitch_block_description_print(letter->block);
    printf("\n");
}

void pes_letter_free(struct pes_letter *letter)
{
    free(letter);
}
