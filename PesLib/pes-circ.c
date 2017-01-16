#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-circ.h"
#include "pes-point.h"
#include "stitch-block-description.h"

struct pes_circ *pes_circ_read(FILE *file)
{
    struct pes_circ *circ = (struct pes_circ *) malloc(sizeof(struct pes_circ));
    circ->block = stitch_block_description_read(file);
    circ->unknown = binaryReadInt16(file);
    circ->type = binaryReadInt16(file);
    circ->start_angle = binaryReadFloat(file);
    circ->end_angle = binaryReadFloat(file);
    circ->left = binaryReadInt16(file);
    circ->top = binaryReadInt16(file);
    circ->right = binaryReadInt16(file);
    circ->bottom = binaryReadInt16(file);
    return circ;
}

void pes_circ_write(FILE *file, struct pes_circ *circ)
{
    stitch_block_description_write(file, circ->block);
    binaryWriteInt16(file, circ->unknown);
    binaryWriteInt16(file, circ->type);
    binaryWriteFloat(file, circ->start_angle);
    binaryWriteFloat(file, circ->end_angle);
    binaryWriteInt16(file, circ->left );
    binaryWriteInt16(file, circ->top);
    binaryWriteInt16(file, circ->right);
    binaryWriteInt16(file, circ->bottom);
}

void pes_circ_print(struct pes_circ *circ)
{
    stitch_block_description_print(circ->block);
    printf("unknown: %d\n", circ->unknown);
    printf("type: %d\n", circ->type);
    printf("Start Angle: %f\n", circ->start_angle);
    printf("End Angle: %f\n", circ->end_angle);
    printf("Left: %d\n", circ->left);
    printf("Top: %d\n", circ->top);
    printf("Right: %d\n", circ->right);
    printf("Bottom: %d\n", circ->bottom);
}

void pes_circ_free(struct pes_circ *circ)
{
    free(circ->block);
    free(circ);
}

