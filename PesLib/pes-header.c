#include <stdio.h>
#include <stdlib.h>
#include "affine-transform.h"
#include "helpers-binary.h"
#include "pes-header.h"

static float getVersion(char *signature)
{
    int tempVersion = atoi(signature + 4);
    if(tempVersion < 10) return (float)tempVersion;
    return tempVersion / 10.0f; 
}

struct pes_header *pes_header_new()
{
    struct pes_header *header = (struct pes_header *) malloc(sizeof(struct pes_header));
    return header;
}

struct pes_header *pes_header_read(FILE *file)
{
    int i, j;
    struct pes_header *header = (struct pes_header *) malloc(sizeof(struct pes_header));
    binaryReadBytes(file, (unsigned char *)header->signature, 8);
    header->signature[8] = '\0';
    header->pecOffset = binaryReadInt32(file);
    header->version = getVersion(header->signature);
    if(header->version == 2.0f)
    {
        header->width = binaryReadUInt16(file);
        header->height = binaryReadUInt16(file);
        header->sewingArea = binaryReadInt16(file); // 1 means "UseExistingDesignArea" 0 means "Design Page Area"
        header->designPageBackgroundColor = binaryReadInt16(file);
        header->designPageForegroundColor = binaryReadInt16(file);
        header->ShowGrid = (binaryReadInt16(file) == 1);
        header->WithAxes = (binaryReadInt16(file) == 1);
        header->SnapToGrid = (binaryReadInt16(file) == 1);
        header->GridInterval = binaryReadInt16(file);
        header->p9 = binaryReadInt16(file); // curves?
        header->OptimizeEntryExitPoints = (binaryReadInt16(file) == 1);
        return header;
    }

    header->hoopSize = binaryReadInt16(file); // 0 = 100x100 else 130x180 or above
    
    header->otherHoopData = binaryReadByte(file);
    header->otherHoopData2 = binaryReadByte(file);
    
    if(header->version == 1.0f)
    {
        return header;
    }
    if(header->version == 3.0f)
    {
        header->width = binaryReadUInt16(file);
        header->height = binaryReadUInt16(file);
        header->sewingArea = binaryReadInt16(file); // 1 means "UseExistingDesignArea" 0 means "Design Page Area"
        header->designPageBackgroundColor = binaryReadInt16(file);
        header->designPageForegroundColor = binaryReadInt16(file);
        header->ShowGrid = (binaryReadInt16(file) == 1);
        header->WithAxes = (binaryReadInt16(file) == 1);
        header->SnapToGrid = (binaryReadInt16(file) == 1);
        header->GridInterval = binaryReadInt16(file);
        header->p9 = binaryReadInt16(file); // curves?
        header->OptimizeEntryExitPoints = (binaryReadInt16(file) == 1);
        return header;
    }
    header->DesignStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)header->DesignName, header->DesignStringLength);
    header->DesignName[header->DesignStringLength] = '\0';
    
    header->categoryStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)header->Category, header->categoryStringLength);
    header->Category[header->categoryStringLength] = '\0';
    
    header->authorStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)header->Author, header->authorStringLength);
    header->Author[header->authorStringLength] = '\0';
    
    header->keywordsStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)header->keywords, header->keywordsStringLength);
    header->keywords[header->keywordsStringLength] = '\0';
    
    header->commentsStringLength = binaryReadByte(file);
    binaryReadBytes(file, (unsigned char *)header->Comments, header->commentsStringLength);
    header->Comments[header->commentsStringLength] = '\0';
    
    header->optimizeHoopChange = (binaryReadInt16(file) == 1);
    if(header->version > 4.0f) 
    {
        header->designPageIsCustom = (binaryReadInt16(file) == 1);
    }
    header->width = binaryReadInt16(file);
    header->height = binaryReadInt16(file);
    header->sewingArea = binaryReadInt16(file); // 1 means "UseExistingDesignArea" 0 means "Design Page Area"
    //int somethingNew = binaryReadInt16(file);
    if(header->version > 4)
    {
        header->designWidth = binaryReadInt16(file);    
        header->designHeight = binaryReadInt16(file);
        header->designPageSectionWidth = binaryReadInt16(file);
        header->designPageSectionHeight = binaryReadInt16(file);
        header->p6 = binaryReadInt16(file); // 100
        ////Debug.Assert(p6 == 100,"p6 is not 100");
    }
    header->designPageBackgroundColor = binaryReadInt16(file);
    header->designPageForegroundColor = binaryReadInt16(file);
    header->ShowGrid = (binaryReadInt16(file) == 1);
    header->WithAxes = (binaryReadInt16(file) == 1);
    header->SnapToGrid = (binaryReadInt16(file) == 1);
    header->GridInterval = binaryReadInt16(file);
    if(header->version > 4)
    {
        header->p9 = binaryReadInt16(file); // curves?
        //Debug.Assert(p9 == 1,"p9 is not 1");
        header->OptimizeEntryExitPoints = (binaryReadInt16(file) == 1);
    
        header->fromImageStringLength = binaryReadByte(file);
        header->FromImageFilename = (char *)malloc(sizeof(char) * header->fromImageStringLength);
        binaryReadBytes(file, (unsigned char *)header->FromImageFilename, header->fromImageStringLength);
        header->FromImageFilename[header->fromImageStringLength] = '\0';
   
        header->imageTransform = affine_transform_read(file); 
            
        header->numberOfProgrammableFillPatterns = binaryReadInt16(file);
        header->programmablePatternFills = (struct pes_pat **) calloc(header->numberOfProgrammableFillPatterns, sizeof(struct pes_pat *));
        
        for(i = 0; i < header->numberOfProgrammableFillPatterns; i++)
        {
            header->programmablePatternFills[i] = pes_pat_read(file);
        }
    }
    header->numberOfMotifPatterns = binaryReadInt16(file);
    header->motifPatterns = (struct motif_data **) calloc(header->numberOfMotifPatterns, sizeof(struct motif_data *));
    for (i = 0; i < header->numberOfMotifPatterns; i++)
    {
        header->motifPatterns[i] = motif_data_read(file);
    }
    header->featherPatternCount = binaryReadInt16(file);
    header->featherPatterns = (struct short_array **) calloc(header->featherPatternCount, sizeof(struct short_array *));
    for(j = 0; j < header->featherPatternCount; j ++)
    {
        header->featherPatterns[j] = short_array_read(file);
    }
    //header->someOtherTypeCount = binaryReadInt16(file);
    header->numberOfColors = binaryReadUInt16(file);
    header->threads = (struct thread_data **) calloc(header->numberOfColors, sizeof(struct thread_data *));
    for (i = 0; i < header->numberOfColors; i++)
    {
        header->threads[i] = thread_data_read(file);
    }
    //int byteR = br.ReadByte();

    return header;
}

void pes_header_print(struct pes_header *header)
{
    int i, j;
    printf("SIGNATURE:                       %s\n", header->signature);
    printf("VERSION:                         %f\n", header->version);
    printf("DESIGN NAME:                     %s\n", header->DesignName);
    printf("CATEGORY:                        %s\n", header->Category);
    printf("AUTHOR:                          %s\n", header->Author);
    printf("KEYWORDS:                        %s\n", header->keywords);
    printf("COMMENTS:                        %s\n", header->Comments);
    printf("OPTIMIZE HOOP CHANGE:            %s\n", header->optimizeHoopChange ? "true" : "false");
    printf("CUSTOM DESIGN PAGE:              %s\n", header->designPageIsCustom ? "true" : "false");

    printf("WIDTH:                           %d\n", header->width);
    printf("HEIGHT:                          %d\n", header->height);
    printf("SEWING AREA:                     %d\n", header->sewingArea); // 1 means "UseExistingDesignArea" 0 means "Design Page Area" 

    printf("DESIGN WIDTH:                    %d\n", header->designWidth);
    printf("DESIGN HEIGHT:                   %d\n", header->designHeight);
    printf("DESIGN PAGE SECTION Width:       %d\n", header->designPageSectionWidth);
    printf("DESIGN PAGE SECTION Height:      %d\n", header->designPageSectionHeight);
    printf("p6:                              %d\n", header->p6);
    ////Debug.Assert(p6 == 100,"p6 is not 100");
    printf("DESIGN PAGE Background:          %d\n", header->designPageBackgroundColor);
    printf("DESIGN PAGE Foreground:          %d\n", header->designPageForegroundColor);
    printf("Show Grid:                       %s\n", header->ShowGrid ? "true" : "false");
    printf("With Axes:                       %s\n", header->WithAxes ? "true" : "false");
    printf("Snap To Grid:                    %s\n", header->SnapToGrid ? "true" : "false");
    printf("Grid Interval:                   %d\n", header->GridInterval);
    printf("p9:                              %d\n", header->p9);
    //Debug.Assert(p9 == 1,"p9 is not 1");
    printf("Optimize Entry/Exit Points:      %s\n", header->OptimizeEntryExitPoints ? "true" : "false");
    
    printf("IMAGE:                           %s\n", header->FromImageFilename);
    affine_transform_print(header->imageTransform); 
          
    printf("Programmable Fill Pattern Count: %d\n", header->numberOfProgrammableFillPatterns);
    for(i = 0; i < header->numberOfProgrammableFillPatterns; i++)
    {
        pes_pat_print(header->programmablePatternFills[i]);
    }

    printf("Motif Pattern Count:             %d\n", header->numberOfMotifPatterns);
    for (i = 0; i < header->numberOfMotifPatterns; i++)
    {
        motif_data_print(header->motifPatterns[i]);
    }
    printf("Feather Pattern Count:          %d\n", header->featherPatternCount);
    for(j = 0; j < header->featherPatternCount; j++)
    {
        short_array_print(header->featherPatterns[j]);
    }
    printf("Number Of Colors:               %d\n", header->numberOfColors);
    for (i = 0; i < header->numberOfColors; i++)
    {
        printf("COLOR #%d\n=============\n", i+1);
        thread_data_print(header->threads[i]);
        printf("\n");
    }
}

void pes_header_free(struct pes_header* header)
{
    if(header->FromImageFilename)
    {
        free(header->FromImageFilename);
    }
}

