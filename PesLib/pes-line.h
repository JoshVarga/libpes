#ifndef CEMBLINE_H
#define CEMBLINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pes-point.h"
#include "stitch-block-description.h"

struct pes_line
{
    struct stitch_block_description *block;
    short unknown;
    short vertex_count;
    struct pes_point **vertex_list;
};

struct pes_line *pes_line_read(FILE *file);
void pes_line_print(struct pes_line *line);
void pes_line_free(struct pes_line *line);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBLINE_H */

