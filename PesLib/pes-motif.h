#ifndef MOTIF_H
#define MOTIF_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct motif_stitch
{
    short offset;
    short width;
    short height;
    short h_arrange;
    short v_arrange;
    short spacing;
    short run_pitch;
};

struct motif
{
    short spacing;
    short width;
    short height;
    short h_arrange;
    short v_arrange;
    short h_spacing;
    short v_spacing;
};

struct motif *motif_read(FILE *file);
void motif_write(FILE *file, struct motif *motif);
void motif_print(struct motif *item);
void motif_free(struct motif *m);

struct motif_stitch *motif_stitch_read(FILE *file);
void motif_stitch_write(FILE *file, struct motif_stitch *motif_stitch);
void motif_stitch_print(struct motif_stitch *item);
void motif_stitch_free(struct motif_stitch *m);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MOTIF_H */

