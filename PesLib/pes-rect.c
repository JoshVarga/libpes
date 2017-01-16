#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-rect.h"
#include "stitch-block-description.h"

struct emb_rect *emb_rect_read(FILE *file)
{
    struct emb_rect *rect = (struct emb_rect *) malloc(sizeof(struct emb_rect));
    rect->header = stitch_block_description_read(file);
    rect->corner_radius = binaryReadInt16(file);
    rect->unknown = binaryReadInt16(file); 
    rect->top = binaryReadInt16(file);
    rect->left = binaryReadInt16(file);
    rect->bottom = binaryReadInt16(file);
    rect->right = binaryReadInt16(file);
    return rect;
}

void emb_rect_print(struct emb_rect *rect)
{
    stitch_block_description_print(rect->header);
    printf("Corner Radius:       %d\n", rect->corner_radius);
    printf("Unknown:             %d\n", rect->unknown);
    printf("Top:                 %d\n", rect->top);
    printf("Left:                %d\n", rect->left);
    printf("Bottom:              %d\n", rect->bottom);
    printf("Right:               %d\n", rect->right);
}

void emb_rect_free(struct emb_rect *rect)
{
    free(rect->header);
    free(rect);
}

