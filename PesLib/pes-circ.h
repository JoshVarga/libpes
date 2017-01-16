#ifndef CEMBCIRC_H
#define CEMBCIRC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stitch-block-description.h"

struct pes_circ
{
    /**
      The stitch block description
      */
    struct stitch_block_description *block;
    short unknown;
    short type;
    float start_angle;
    float end_angle;
    short left;
    short top;
    short right;
    short bottom;
};

struct pes_circ *pes_circ_read(FILE *file);
void pes_circ_write(FILE *file, struct pes_circ *circ);
void pes_circ_print(struct pes_circ *circ);
void pes_circ_free(struct pes_circ *circ);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CEMBCIRC_H */

