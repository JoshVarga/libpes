#include <stdio.h>
#include <stdlib.h>
#include "affine-transform.h"
#include "helpers-binary.h"

struct affine_transform *affine_transform_read(FILE *file)
{
    struct affine_transform *transform;
    transform = (struct affine_transform *)malloc(sizeof(*transform));
    transform->m1_1 = binaryReadFloat(file);
    transform->m1_2 = binaryReadFloat(file);
    transform->m1_3 = binaryReadFloat(file);
    transform->m2_1 = binaryReadFloat(file);
    transform->m2_2 = binaryReadFloat(file);
    transform->m2_3 = binaryReadFloat(file);
    return transform;
}

void affine_transform_write(FILE *file, struct affine_transform *transform)
{
    binaryWriteFloat(file, transform->m1_1);
    binaryWriteFloat(file, transform->m1_2);
    binaryWriteFloat(file, transform->m1_3);
    binaryWriteFloat(file, transform->m2_1);
    binaryWriteFloat(file, transform->m2_2);
    binaryWriteFloat(file, transform->m2_3);
}


void affine_transform_print(struct affine_transform *transform)
{
    printf("Transform:\n");
    printf("%f %f %f\n", transform->m1_1, transform->m1_2, transform->m1_3);
    printf("%f %f %f\n\n", transform->m2_1, transform->m2_2, transform->m2_3);
}

void affine_transform_free(struct affine_transform *transform)
{
    free(transform);
}