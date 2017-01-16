#include <stdio.h>
#include <stdlib.h>

#include "helpers-binary.h"
#include "pes-group-object.h"

struct pes_group_object *pes_group_object_read(FILE *file)
{
    int i;
    struct pes_group_object *group = (struct pes_group_object *) malloc(sizeof(struct pes_group_object));
    group->identifier = binaryReadInt16(file);
    group->item_count = binaryReadInt16(file);
    group->items = (int *) calloc(group->item_count, sizeof(int));
    for(i = 0; i < group->item_count; i++)
    {
        group->items[i] = binaryReadInt16(file);
    }
    return group;
}

