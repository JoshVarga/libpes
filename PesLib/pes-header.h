#ifndef PES_HEADER_H
#define PES_HEADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "affine-transform.h"
#include "short-array.h"
#include "pes-motif.h"
#include "pes-motif-data.h"
#include "pes_pat.h"
#include "pes-thread.h"

struct pes_header 
{
    char signature[9];
    int pecOffset;
    float version;
    short hoopSize;
    char otherHoopData;
    char otherHoopData2;
    unsigned char DesignStringLength;
    char DesignName[100];
    unsigned char categoryStringLength;
    char Category[100];
    unsigned char authorStringLength;
    char Author[100];
    unsigned char keywordsStringLength;
    char keywords[100];
    unsigned char commentsStringLength;
    char Comments[100];
    short optimizeHoopChange; /* bool */
    short designPageIsCustom; /* bool */
    unsigned short width;
    unsigned short height;
    short sewingArea; // 1 means "UseExistingDesignArea" 0 means "Design Page Area"
    short somethingNew;
    unsigned short designWidth;
    unsigned short designHeight;
    unsigned short designPageSectionWidth;
    unsigned short designPageSectionHeight;
    unsigned short unknown; // 100
    short p6;
    short designPageBackgroundColor;
    short designPageForegroundColor;
    short ShowGrid; /* bool */
    short WithAxes; /* bool */
    short SnapToGrid; /* bool */
    short GridInterval;
    short p9; // curves?
    
    short OptimizeEntryExitPoints; /* bool */
    unsigned char fromImageStringLength;
    char *FromImageFilename;
    struct affine_transform *imageTransform; 
            
    short numberOfProgrammableFillPatterns;
    struct pes_pat **programmablePatternFills;
    short numberOfMotifPatterns;
    struct motif_data **motifPatterns;
    
    short featherPatternCount;
    struct short_array **featherPatterns; /* list of pointers */

    int numberOfColors;
    struct thread_data **threads;
    
    char byteR;
};

struct pes_header *pes_header_read(FILE *file);
void pes_header_print(struct pes_header *header);
void pes_header_free(struct pes_header* header);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PES_HEADER_H */

