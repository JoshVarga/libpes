#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "block-geometry.h"
#include "helpers-binary.h"
#include "pes-letter.h"
#include "pes-ntext.h"

struct pes_ntext *pes_ntext_read(FILE *file)
{
    int count, i, typeStringLength;
    char typeString[50];
    struct pes_ntext *text = (struct pes_ntext *) malloc(sizeof(struct pes_ntext));
    text->geometry = block_geometry_read(file);

    count = binaryReadInt16(file);
    for(i = 0; i < count; i++)
    {
        binaryReadInt32(file);
        typeStringLength = binaryReadInt16(file);
        binaryReadBytes(file, (unsigned char *)typeString, typeStringLength);
        typeString[typeStringLength] = '\0';
        printf("%s\n", typeString);
        if(strcmp(typeString, "CLetter") == 0)
        {
            text->letter = pes_letter_read(file);
        }
    }
    return text;
}

void pes_ntext_print(struct pes_ntext *text)
{
    block_geometry_print(text->geometry);
    pes_letter_print(text->letter);
}

void pes_ntext_free(struct pes_ntext *text)
{
    block_geometry_free(text->geometry);
    free(text);
}
