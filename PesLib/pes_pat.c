#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes_pat.h"

struct pes_pat *pes_pat_read(FILE *file)
{
    int i;
    struct pes_pat *pattern;
    pattern = (struct pes_pat *)malloc(sizeof(*pattern));
    pattern->count = binaryReadInt16(file);
    pattern->tile_lines = (struct tile_line **) calloc(pattern->count, sizeof(struct tile_line *));
    for (i = 0; i < pattern->count; i++)
    {
        pattern->tile_lines[i] = tile_line_read(file);
    }
    return pattern;
}

void pes_pat_print(struct pes_pat *fill)
{
    int i;
    printf("PROGRAMMABLE FILL\n");
    printf("=================\n");
    printf("TILE LINE COUNT %d\n", fill->count);
    for(i = 0; i < fill->count; i++)
    {
        printf("TILE LINE #%d\n", i);
        printf("=================\n");
        tile_line_print(fill->tile_lines[i]);
    }
}

void pes_pat_free(struct pes_pat *patToFree)
{
    int i;
    for(i = 0; i < patToFree->count; i++)
    {
        tile_line_free(patToFree->tile_lines[i]);
    }
}

