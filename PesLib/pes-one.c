#include "affine-transform.h"
#include "pes-one.h"
#include "helpers-binary.h"
#include <stdio.h>
#include <stdlib.h>

struct pes_one *pes_one_read(FILE *file)
{
    struct pes_one *embone = (struct pes_one *)malloc(sizeof(struct pes_one));
    embone->geometry = block_geometry_read(file);
           
    embone->unknown = binaryReadInt16(file);
    embone->translate_x = binaryReadInt16(file);
    embone->translate_y = binaryReadInt16(file);
    embone->width = binaryReadInt16(file);
    embone->height = binaryReadInt16(file);
    
    binaryReadBytes(file, embone->other, 8);
    return embone;
}

void pes_one_print(struct pes_one *embOne)
{
    int i;
    printf("\nCEmbOne\n");
    printf("=============\n");
    block_geometry_print(embOne->geometry);

    printf("Unknown:     %d\n", embOne->unknown);
    printf("TranslateX:  %d\n", embOne->translate_x);
    printf("TranslateY:  %d\n", embOne->translate_y);
    printf("Width:       %d\n", embOne->width);
    printf("Height:      %d\n", embOne->height);

    printf("Other:       ");
    for(i = 0; i < 8; i++)
    {
        printf("%x ", embOne->other[i]);
    }
}

void pes_one_free(struct pes_one *embOne)
{
    free(embOne->geometry);
}

