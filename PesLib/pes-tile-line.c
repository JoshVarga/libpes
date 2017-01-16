#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "tile-line.h"

struct tile_line *tile_line_read(FILE *file)
{
    int i;
    struct tile_line *tileLine;
    tileLine = (struct tile_line *)malloc(sizeof(*tileLine));
    tileLine->unknown1 = binaryReadInt16(file);
    tileLine->unknown2 = binaryReadInt16(file);
    tileLine->unknown3 = binaryReadInt16(file);
    tileLine->unknown4 = binaryReadInt16(file);
    tileLine->tileLinePointCount = binaryReadInt16(file);
    tileLine->pointList = (struct point **)malloc(sizeof(struct point *) * tileLine->tileLinePointCount);
    for (i = 0; i < tileLine->tileLinePointCount; i++)
    {
        tileLine->pointList[i] = point_new(binaryReadInt16(file), binaryReadInt16(file));
    }
    return tileLine;
}

void tile_line_print(struct tile_line *line)
{
    int i;
    printf("TILE LINE\n");
    printf("===============\n");
    printf("UNKNOWN 1: %d\n", line->unknown1);
    printf("UNKNOWN 2: %d\n", line->unknown1);
    printf("UNKNOWN 3: %d\n", line->unknown1);
    printf("UNKNOWN 4: %d\n", line->unknown1);
    printf("TILE LINE POINT COUNT: %d\n", line->tileLinePointCount);
    for(i = 0; i < line->tileLinePointCount; i++)
    {
        point_print(line->pointList[i]);
    }
}

void tile_line_free(struct tile_line *lineToFree)
{
    int i;
    for(i = 0; i < lineToFree->tileLinePointCount; i++)
    {
        free(lineToFree->pointList[i]);
    }
}

