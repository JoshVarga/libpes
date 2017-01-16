#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers-binary.h"
#include "pes-punch.h"
#include "pes-sew-fig-seg.h"

struct pes_punch *pes_punch_read(FILE *file)
{
    int i, count;
    char typeString[50];
    unsigned short separator, separator2, typeStringLength;
    struct pes_punch *embPunch;
    embPunch = (struct pes_punch *)malloc(sizeof(*embPunch));
    embPunch->geometry = block_geometry_read(file);
    count = binaryReadInt16(file);
    for(i = 0; i < count; i++)
    {
        separator = binaryReadInt16(file);
        if(separator == 0xFFFF)
        {
            separator2 = binaryReadInt16(file);
            typeStringLength = binaryReadInt16(file);
            binaryReadBytes(file, (unsigned char *)typeString, typeStringLength);
            typeString[typeStringLength] = '\0';
        }
        printf("%s\n", typeString);
        if(strcmp(typeString, "CSewFigSeg") == 0)
        {
            struct pes_sew_fig_seg *item = pes_sew_fig_seg_read(file);
            pes_sew_fig_seg_print(item);
        }
    }
    return embPunch;
}

void pes_punch_print(struct pes_punch *item)
{
    block_geometry_print(item->geometry);
}

void pes_punch_free(struct pes_punch *item)
{
    block_geometry_free(item->geometry);
    free(item);
}
