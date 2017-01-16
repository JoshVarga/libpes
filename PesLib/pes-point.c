#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes-point.h"
#include "point.h"

struct pes_point *pes_point_read(FILE *file)
{
    struct pes_point *temp = (struct pes_point *) malloc(sizeof(struct pes_point));
    temp->p1 = point_read(file);
    temp->p2 = point_read(file);
    temp->p3 = point_read(file);
    temp->stitch_type = binaryReadInt16(file);
    return (temp);
}

void pes_point_print(struct pes_point *point)
{
    printf("PES POINT\n");
    printf("================\n");
    point_print(point->p1);
    point_print(point->p2);
    point_print(point->p3);
    printf("Stitch Type:     %d\n", point->stitch_type);
    printf("\n");
}

void pes_point_free(struct pes_point *point)
{
    free(point->p1);
    free(point->p2);
    free(point->p3);
    free(point);
}

