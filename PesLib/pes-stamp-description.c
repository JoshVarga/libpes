#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-stamp-description.h"

struct pes_stamp_description *pes_stamp_description_read(FILE *file)
{
    struct pes_stamp_description *stamp = (struct pes_stamp_description *)malloc(sizeof(struct pes_stamp_description));
    stamp->top = binaryReadInt16(file);
    stamp->left = binaryReadInt16(file);
    stamp->width = binaryReadInt16(file);
    stamp->height = binaryReadInt16(file);
    stamp->angle = binaryReadInt16(file);
    stamp->stamp_index = binaryReadInt16(file);
    return stamp;
}

void pes_stamp_description_print(struct pes_stamp_description *stamp)
{
    printf("Top:      %d\n", stamp->top);
    printf("Left:     %d\n", stamp->left);
    printf("Width:    %d\n", stamp->width);
    printf("Height:   %d\n", stamp->height);
    printf("Angle:    %d\n", stamp->angle);
    printf("Index:    %d\n", stamp->stamp_index);
}

void pes_stamp_description_free(struct pes_stamp_description *stamp)
{
    free(stamp);
}
