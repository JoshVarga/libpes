#ifndef CGROUPOBJECT_H
#define CGROUPOBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

struct pes_group_object
{
    int identifier;
    int item_count;
    int *items;
};

struct pes_group_object *pes_group_object_read(FILE *file);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CGROUPOBJECT_H */

