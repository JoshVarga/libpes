#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes-motif-data.h"
#include "tile-line.h"

struct motif_data *motif_data_read(FILE *file)
{
    struct motif_data *data;
    int i;
    data = (struct motif_data *) malloc(sizeof(struct motif_data));
    data->tileLineCount = binaryReadUInt16(file);
    data->tile_lines = (struct tile_line **) calloc(data->tileLineCount, sizeof(struct tile_line *));
    for (i = 0; i < data->tileLineCount; i++)
    {
        data->tile_lines[i] = tile_line_read(file);
    }
    return data;
}

void motif_data_print(struct motif_data *data)
{
    int i;
    printf("LINE COUNT: %d\n", data->tileLineCount);
    for (i = 0; i < data->tileLineCount; i++)
    {
        tile_line_print(data->tile_lines[i]);
    }
}

void motif_data_free(struct motif_data* data)
{
    /*int i;
    for(i = 0; i < data->tileLineCount; i++)
    {
        free(data->tileLines[i]);
    }
    free(data->tileLines);*/
    free(data);
}

