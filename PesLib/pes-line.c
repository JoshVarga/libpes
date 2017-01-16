#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-line.h"
#include "pes-point.h"
#include "stitch-block-description.h"

struct pes_line *pes_line_read(FILE *file)
{
    int i;
    struct pes_line *line = (struct pes_line *) malloc(sizeof(struct pes_line));
    line->block = stitch_block_description_read(file);
    line->unknown = binaryReadInt16(file);
    line->vertex_count = binaryReadInt16(file);
    line->vertex_list = (struct pes_point **) calloc(line->vertex_count, sizeof(struct pes_point *));
    for(i = 0; i < line->vertex_count; i++)
    {
        line->vertex_list[i] = pes_point_read(file);
    }
    return line;
}

void pes_line_print(struct pes_line *line)
{
    int i;
    stitch_block_description_print(line->block);
    printf("unknown: %d\n", line->unknown);
    printf("Count: %d\n", line->vertex_count);
    
    for(i = 0; i < line->vertex_count; i++)
    {
         pes_point_print(line->vertex_list[i]);
    }
}

void pes_line_free(struct pes_line *line)
{
    free(line->block);
    free(line);
}

