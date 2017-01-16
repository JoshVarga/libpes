#include "helpers-binary.h"
#include "block-geometry.h"
#include <stdio.h>
#include <stdlib.h>

struct block_geometry *block_geometry_read(FILE *file)
{
    struct block_geometry *block = (struct block_geometry *)malloc(sizeof(struct block_geometry));
    
    block->left = binaryReadInt16(file);
    block->top = binaryReadInt16(file);
    block->right = binaryReadInt16(file);
    block->bottom = binaryReadInt16(file);

    block->leftPosition = binaryReadInt16(file);
    block->topPosition = binaryReadInt16(file);
    block->rightPosition = binaryReadInt16(file);
    block->bottomPosition = binaryReadInt16(file);
    block->transform = affine_transform_read(file);
    return block;
}

void block_geometry_write(FILE *file, struct block_geometry *block)
{
    binaryWriteInt16(file, block->left);
    binaryWriteInt16(file, block->top);
    binaryWriteInt16(file, block->right);
    binaryWriteInt16(file, block->bottom);

    binaryWriteInt16(file, block->leftPosition);
    binaryWriteInt16(file, block->topPosition);
    binaryWriteInt16(file, block->rightPosition);
    binaryWriteInt16(file, block->bottomPosition);
    affine_transform_write(file, block->transform);
}

void block_geometry_print(struct block_geometry *block)
{
    printf("Left:   %d\n", block->left);
    printf("Top:    %d\n", block->top);
    printf("Right:  %d\n", block->right);
    printf("Bottom: %d\n", block->bottom);

    printf("Left:   %d\n", block->leftPosition);
    printf("Top:    %d\n", block->topPosition);
    printf("Right:  %d\n", block->rightPosition);
    printf("Bottom: %d\n", block->bottomPosition);

    affine_transform_print(block->transform);
}

void block_geometry_free(struct block_geometry *block)
{
    free(block->transform);
    free(block);
}