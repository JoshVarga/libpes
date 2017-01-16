#include <stdio.h>
#include <string.h>

#include "pes-circ.h"
#include "pes-header.h"
#include "pes-line.h"
#include "pes-ntext.h"
#include "pes-one.h"
#include "pes-punch.h"
#include "pes-rect.h"
#include "pes-special-shape.h"
#include "helpers-binary.h"

int main(int argc, char* argv[])
{
    int i, count, typeStringLength;
    unsigned short separator, separator2;
    char typeString[50];
    struct pes_header *header;
    struct pes_one *embOne;
    FILE *file = fopen(argv[1], "rb");
    printf("FILENAME: %s\n", argv[1]);
    header = pes_header_read(file);
    
    pes_header_print(header);
    count = binaryReadInt16(file);
    for(i = 0; i < count; i++)
    {
        separator = binaryReadInt16(file);
        if(separator == 0xFFFF)
        {
            separator2 = binaryReadInt16(file);
            typeStringLength = binaryReadInt16(file);
            binaryReadBytes(file, (unsigned char *)typeString, typeStringLength);
            typeString[typeStringLength] = '\0';
        }
        printf("%s\n", typeString);
        if(strcmp(typeString, "CEmbOne") == 0)
        {
            embOne = pes_one_read(file);
            pes_one_print(embOne);
        }
        else if(strcmp(typeString, "CEmbPunch") == 0)
        {
            struct pes_punch *item = pes_punch_read(file);
            pes_punch_print(item);
        }
        else if(strcmp(typeString, "CEmbRect") == 0)
        {
            struct emb_rect *embrect = emb_rect_read(file);
            emb_rect_print(embrect);
        }
        else if(strcmp(typeString, "CEmbNText") == 0)
        {
            struct pes_ntext *emb_n_text = pes_ntext_read(file);
            pes_ntext_print(emb_n_text);
        }
        else if(strcmp(typeString, "CEmbSpecialShape") == 0)
        {
            struct pes_special_shape *shape = pes_special_shape_read(file);
            pes_special_shape_print(shape);
        }
        else if(strcmp(typeString, "CEmbLine") == 0)
        {
            struct pes_line *shape = pes_line_read(file);
            pes_line_print(shape);
        }
        else if(strcmp(typeString, "CEmbCirc") == 0)
        {
            struct pes_circ *shape = pes_circ_read(file);
            pes_circ_print(shape);
        }
    }
    fclose(file);
	return 0;
}

