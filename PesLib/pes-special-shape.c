#include <stdio.h>
#include <stdlib.h>

#include "block-geometry.h"
#include "helpers-binary.h"
#include "pes-special-shape.h"
#include "stitch-block-description.h"

struct pes_special_shape *pes_special_shape_read(FILE *file)
{
    int i;
    struct pes_special_shape *shape = (struct pes_special_shape *) malloc(sizeof(struct pes_special_shape));
    shape->header = stitch_block_description_read(file);

    shape->v0 = binaryReadInt16(file);
    shape->NumberOfPoints = binaryReadInt16(file);
    shape->points = (struct pes_point **) calloc(shape->NumberOfPoints, sizeof(struct pes_point *));
    for(i = 0; i < shape->NumberOfPoints; i++)
    {
        shape->points[i] = pes_point_read(file);
    }
    shape->v1 = binaryReadInt16(file); // 0x8001
    shape->v2 = binaryReadInt16(file);
    shape->v3 = binaryReadInt16(file);
    shape->v4 = binaryReadInt16(file);
    shape->v5 = binaryReadInt16(file);
    shape->v6 = binaryReadInt16(file);
    shape->v7 = binaryReadInt16(file);
    shape->v8 = binaryReadInt16(file);
    shape->v9 = binaryReadInt16(file);
    shape->v10 = binaryReadInt16(file);
    shape->v11 = binaryReadInt16(file);// 0x3F80
    shape->v12 = binaryReadInt16(file);
    shape->v13 = binaryReadInt16(file);
    shape->v14 = binaryReadInt16(file);
    shape->v15 = binaryReadInt16(file);
    shape->v16 = binaryReadInt16(file);
    return shape;
}

void pes_special_shape_print(struct pes_special_shape *shape)
{
    int i;
    printf("CEmbSpecialShape\n");
    printf("===================\n");
    stitch_block_description_print(shape->header);
    printf("UNKNOWN 0: %d\n", shape->v0);
    for(i = 0; i < shape->NumberOfPoints; i++)
    {
        pes_point_print(shape->points[i]);
    }
    printf("UNKNOWN 1: %d\n", shape->v1);
    printf("UNKNOWN 2: %d\n", shape->v2);
    printf("UNKNOWN 3: %d\n", shape->v3);
    printf("UNKNOWN 4: %d\n", shape->v4);
    printf("UNKNOWN 5: %d\n", shape->v5);
    printf("UNKNOWN 6: %d\n", shape->v6);
    printf("UNKNOWN 7: %d\n", shape->v7);
    printf("UNKNOWN 8: %d\n", shape->v8);
    printf("UNKNOWN 9: %d\n", shape->v9);
    printf("UNKNOWN 10: %d\n", shape->v10);
    printf("UNKNOWN 11: %d\n", shape->v11);
    printf("UNKNOWN 12: %d\n", shape->v12);
    printf("UNKNOWN 13: %d\n", shape->v13);
    printf("UNKNOWN 14: %d\n", shape->v14);
    printf("UNKNOWN 15: %d\n", shape->v15);
    printf("UNKNOWN 16: %d\n", shape->v16);
}

void pes_special_shape_free(struct pes_special_shape *shape)
{
    stitch_block_description_free(shape->header);
    free(shape->points);
    free(shape);
}