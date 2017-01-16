#include "affine-transform.h"
#include "pes-point.h"
#include "pes-sew-fig-seg.h"
#include "helpers-binary.h"
#include <stdio.h>
#include <stdlib.h>

struct pes_sew_fig_seg *pes_sew_fig_seg_read(FILE *file)
{
    int i;
    struct pes_sew_fig_seg *block = (struct pes_sew_fig_seg *) malloc(sizeof(struct pes_sew_fig_seg));
    block->colorIndex = binaryReadInt16(file);
    block->unknown = binaryReadInt16(file);
    block->sideOneStitches = binaryReadInt16(file);
    block->pointsSide1 = (struct pes_point **) calloc(block->sideOneStitches, sizeof(struct pes_point *));
    for (i = 0; i < block->sideOneStitches; i++)
    {
        block->pointsSide1[i] = pes_point_read(file);
    }
    block->pointsSide2 = (struct pes_point **) calloc(block->sideOneStitches, sizeof(struct pes_point *));
    block->sideTwoStitches = binaryReadInt16(file);
    for (i = 0; i < block->sideTwoStitches; i++)
    {
        block->pointsSide2[i] = pes_point_read(file);
    }

    block->RunPitch = binaryReadInt16(file);
    block->FillType = binaryReadInt16(file); // Satin = 0, Fill = 1, Programmable Fill = 2
    block->RegionDensity = binaryReadInt16(file);
    block->something2 = binaryReadInt16(file);

    block->BaseSewingStepPitch = binaryReadInt16(file) / 10.0f;
    block->BaseSewingFrequency = binaryReadInt16(file);
    block->BaseSewingStitchType = binaryReadInt16(file);
    block->FillHalfStitch = binaryReadInt16(file);
    block->useFillAreaUnderSewing = binaryReadInt16(file); // Use UseFillUnderSew

    block->FillAreaUnderSewingType = binaryReadInt16(file); // 0 = 1 direction, 1 = both directions
    //block->RunningStitchPath = binaryReadInt16(file); // half-stitch?
    
        binaryReadInt16(file);
    

    block->ProgrammableFillPatternIndex = binaryReadInt16(file);  //20
    block->ProgrammableFillWidth = binaryReadInt16(file);
    block->ProgrammableFillHeight = binaryReadInt16(file);
    block->ProgrammableFillRowOrColumn = binaryReadInt16(file);
    block->ProgrammableFillRowOffset = binaryReadInt16(file);
    block->ProgrammableFillColumnOffset = binaryReadInt16(file);
    block->ProgrammableFillDirection = binaryReadInt16(file); 
    // Motif section
    
    binaryReadInt16(file);

    block->UseBaseSewing = binaryReadInt16(file);
    block->PullCompensation = binaryReadInt16(file);
    
    block->IsTopFeathered = binaryReadInt16(file);
    block->IsBottomFeathered = binaryReadInt16(file);
    block->FeatherTopLength = binaryReadInt16(file);
    block->FeatherBottomLength = binaryReadInt16(file);
    block->PipingDensity = binaryReadInt16(file);
    block->PipingRunPitch = binaryReadInt16(file);
    block->PipingFrequency = binaryReadInt16(file);
    block->numberOfStamps = binaryReadInt16(file); 

    block->UseMotifPattern1 = binaryReadInt16(file); // default: false

    block->MotifFillPattern1 = motif_read(file);
    
    block->UseMotifPattern2 = binaryReadInt16(file); // default: false
    
    block->MotifFillPattern2 = motif_read(file);
    
    block->MotifRowOffset = binaryReadInt16(file);
    block->MotifRunPitch = binaryReadInt16(file); //default: 100
    
    block->OutlineEntryv1 = binaryReadInt16(file);
    block->OutlineEntry = binaryReadFloat(file);
    
    block->OutlineExitv1 = binaryReadInt16(file);
    block->OutlineExit = binaryReadFloat(file);
    
    block->RegionEntryv1 = binaryReadInt16(file);
    block->RegionEntry = binaryReadFloat(file);
    
    block->RegionExitv1 = binaryReadInt16(file);
    block->RegionExit = binaryReadFloat(file);
    
    return block;
}

void pes_sew_fig_seg_print(struct pes_sew_fig_seg *block)
{
    int i;
    printf("colorIndex:      %d\n", block->colorIndex);
    printf("unknown:      %d\n", block->unknown);
    printf("sideOneStitches:      %d\n", block->sideOneStitches);
    for (i = 0; i < block->sideOneStitches; i++)
    {
        pes_point_print(block->pointsSide1[i]);
    }
    printf(":      %d\n", block->sideTwoStitches);
    for (i = 0; i < block->sideTwoStitches; i++)
    {
        pes_point_print(block->pointsSide2[i]);
    }

    printf("RunPitch:      %d\n", block->RunPitch);
    printf("FillType:      %d\n", block->FillType);
    printf("RegionDensity:      %d\n", block->RegionDensity);
    printf("something2:      %d\n", block->something2);

    printf("BaseSewingStepPitch:      %d\n", block->BaseSewingStepPitch);
    printf("BaseSewingFrequency:      %d\n", block->BaseSewingFrequency);
    printf("BaseSewingStitchType:      %d\n", block->BaseSewingStitchType);
    printf("FillHalfStitch:      %d\n", block->FillHalfStitch);
    printf("useFillAreaUnderSewing:      %d\n", block->useFillAreaUnderSewing);

    printf("FillAreaUnderSewingType:      %d\n", block->FillAreaUnderSewingType);
    //printf("RunningStitchPath:      %d\n", block->RunningStitchPath);
    
    printf("ProgrammableFillPatternIndex:      %d\n", block->ProgrammableFillPatternIndex);
    printf("ProgrammableFillWidth:      %d\n", block->ProgrammableFillWidth);
    printf("ProgrammableFillHeight:      %d\n", block->ProgrammableFillHeight);
    printf("ProgrammableFillRowOrColumn:      %d\n", block->ProgrammableFillRowOrColumn);
    printf("ProgrammableFillRowOffset:      %d\n", block->ProgrammableFillRowOffset);
    printf("ProgrammableFillColumnOffset:      %d\n", block->ProgrammableFillColumnOffset);
    printf("ProgrammableFillDirection:      %d\n", block->ProgrammableFillDirection);

    printf("UseBaseSewing:      %d\n", block->UseBaseSewing);
    printf("PullCompensation:      %d\n", block->PullCompensation);
    
    printf("FeatherTopLength:      %d\n", block->FeatherTopLength);
    printf("FeatherBottomLength:      %d\n", block->FeatherBottomLength);
    printf("PipingDensity:      %d\n", block->PipingDensity);
    printf("PipingRunPitch:      %d\n", block->PipingRunPitch);
    printf("PipingFrequency:      %d\n", block->PipingFrequency);
    printf("numberOfStamps:      %d\n", block->numberOfStamps); 

    printf("Use Motif Pattern1:             %d\n", block->UseMotifPattern1); // default: false
    motif_print(block->MotifFillPattern1);
    motif_print(block->MotifFillPattern2);
    
    printf("MotifRowOffset:                 %d\n", block->MotifRowOffset);
    printf("MotifRunPitch:                  %d\n", block->MotifRunPitch);

    printf("OutlineEntryv1:                 %d\n", block->OutlineEntryv1);
    printf("%f\n", block->OutlineEntry);
    
    printf("OutlineExitv1:                  %d\n", block->OutlineExitv1);
    printf("%f\n", block->OutlineExit);
    
    printf("RegionEntryv1:                  %d\n", block->RegionEntryv1);
    printf("%f\n", block->RegionEntry);
    
    printf("RegionExitv1:                   %d\n", block->RegionExitv1);
    printf("%f\n", block->RegionExit);
}

void pes_sew_fig_seg_free(struct pes_sew_fig_seg *block)
{
    free(block);
}