#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

struct affine_transform
{
    float m1_1;
    float m1_2;
    float m1_3;
    float m2_1;
    float m2_2;
    float m2_3;
};

struct affine_transform *affine_transform_read(FILE *file);
void affine_transform_write(FILE *file, struct affine_transform *transform);
void affine_transform_print(struct affine_transform *transform);
void affine_transform_free(struct affine_transform *transform);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AFFINE_TRANSFORM_H */

