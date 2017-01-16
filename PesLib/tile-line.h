#ifndef TILE_LINE_H
#define TILE_LINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "point.h"

struct tile_line
{
    short unknown1;
    short unknown2;
    short unknown3;
    short unknown4;
    short tileLinePointCount;
    struct point **pointList;
};

struct tile_line *tile_line_read(FILE *file);
void tile_line_print(struct tile_line *line);
void tile_line_free(struct tile_line *line);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TILE_LINE_H */

