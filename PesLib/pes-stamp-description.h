#ifndef PES_STAMP_DESCRIPTION_H
#define PES_STAMP_DESCRIPTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct pes_stamp_description
{
    short top;
    short left;
    short width;
    short height;
    short angle;
    short stamp_index;
};

struct pes_stamp_description *pes_stamp_description_read(FILE *file);
void pes_stamp_description_print(struct pes_stamp_description *stamp);
void pes_stamp_description_free(struct pes_stamp_description *stamp);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PES_STAMP_DESCRIPTION_H */

