#include <stdio.h>
#include <stdlib.h>
#include "helpers-binary.h"
#include "pes-motif.h"

struct motif *motif_read(FILE *file)
{
    struct motif *returnValue = (struct motif *)malloc(sizeof(struct motif));
    returnValue->spacing = binaryReadInt16(file);
    returnValue->width = binaryReadInt16(file);
    returnValue->height = binaryReadInt16(file);
    returnValue->h_arrange = binaryReadInt16(file);
    returnValue->v_arrange = binaryReadInt16(file);
    returnValue->h_spacing = binaryReadInt16(file);
    returnValue->v_spacing = binaryReadInt16(file);
    return returnValue;
}

void motif_write(FILE *file, struct motif *motif)
{
    binaryWriteInt16(file, motif->spacing);
    binaryWriteInt16(file, motif->width);
    binaryWriteInt16(file, motif->height);
    binaryWriteInt16(file, motif->h_arrange);
    binaryWriteInt16(file, motif->v_arrange);
    binaryWriteInt16(file, motif->h_spacing);
    binaryWriteInt16(file, motif->v_spacing);
}

void motif_print(struct motif *item)
{
    printf("MOTIF\n");
    printf("===============\n");
    printf("Spacing:     %d\n", item->spacing);
    printf("Width:       %d\n", item->width);
    printf("Height:      %d\n", item->height);
    printf("H-Arrange:   %d\n", item->h_arrange);
    printf("V-Arrange:   %d\n", item->v_arrange);
    printf("H-Spacing:   %d\n", item->h_spacing);
    printf("V-Spacing:   %d\n", item->v_spacing);
}

void motif_free(struct motif *m)
{
    free(m);
}

struct motif_stitch *motif_stitch_read(FILE *file)
{
    struct motif_stitch *returnValue = (struct motif_stitch *)malloc(sizeof(struct motif_stitch));
    returnValue->offset = binaryReadInt16(file);
    returnValue->width = binaryReadInt16(file);
    returnValue->height = binaryReadInt16(file);
    returnValue->h_arrange = binaryReadInt16(file);
    returnValue->v_arrange = binaryReadInt16(file);
    returnValue->spacing = binaryReadInt16(file);
    returnValue->run_pitch = binaryReadInt16(file);
    return returnValue;
}

void motif_stitch_write(FILE *file, struct motif_stitch *motif_stitch)
{
    binaryWriteInt16(file, motif_stitch->offset);
    binaryWriteInt16(file, motif_stitch->width);
    binaryWriteInt16(file, motif_stitch->height);
    binaryWriteInt16(file, motif_stitch->h_arrange);
    binaryWriteInt16(file, motif_stitch->v_arrange);
    binaryWriteInt16(file, motif_stitch->spacing);
    binaryWriteInt16(file, motif_stitch->run_pitch);
}

void motif_stitch_print(struct motif_stitch *item)
{
    printf("MOTIF-LINE\n");
    printf("===============\n");
    printf("Offset:      %0.1f\n", item->offset / 10.0f);
    printf("Width:       %0.1f\n", item->width / 10.0f);
    printf("Height:      %0.1f\n", item->height / 10.0f);
    printf("H-Arrange:   %d\n", item->h_arrange);
    printf("V-Arrange:   %d\n", item->v_arrange);
    printf("Spacing:     %0.1f\n", item->spacing / 10.0f);
    printf("Run Pitch:   %0.1f\n", item->run_pitch / 10.0f);
}

void motif_stitch_free(struct motif_stitch *m)
{
    free(m);
}