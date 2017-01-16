#ifndef MOTIF_DATA_H
#define MOTIF_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "point.h"

struct motif_data
{
    short tileLineCount;
    struct tile_line **tile_lines;
};

struct motif_data *motif_data_read(FILE *file);
void motif_data_free(struct motif_data* data);
void motif_data_print(struct motif_data *data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MOTIF_DATA_H */

