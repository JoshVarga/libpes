#ifndef CEMBRECT_H
#define CEMBRECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stitch-block-description.h"

struct emb_rect
{
    struct stitch_block_description *header;
    int top;
    int left;
    int bottom;
    int right;
    int corner_radius;
    int unknown;
};

struct emb_rect *emb_rect_read(FILE *file);
void emb_rect_print(struct emb_rect *rect);
void emb_rect_free(struct emb_rect *rect);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBRECT_H */

